#pragma once

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

namespace Drive::CPP17::Trees{

    #define ASSERT assert 
    #ifndef Min
    #define Min std::min
    #endif 
    #ifndef Max
    #define Max std::max
    #endif 
    #ifndef TMAXNODES
    #define TMAXNODES 8
    #endif 
    #ifndef TMINNODES
    #define TMINNODES 4
    #endif 

    #ifndef RTREE_DONT_USE_MEMPOOLS
    #define RTREE_DONT_USE_MEMPOOLS 1
    #endif 

    #ifndef RTREE_USE_SPHERICAL_VOLUME
    #define RTREE_USE_SPHERICAL_VOLUME 1
    #endif

    class RTree{
    protected:

    struct Node; 

    public:

    enum
    {
        MAXNODES = TMAXNODES,                         ///< Max elements in node
        MINNODES = TMINNODES,                         ///< Min elements in node
    };

    public:

    RTree();
    RTree(const RTree& other);
    virtual ~RTree();

    static void exportItem();

    void Insert(const int a_min[2], const int a_max[2], const int& a_dataId);

    void Remove(const int a_min[2], const int a_max[2], const int& a_dataId);

    int Search(const int a_min[2], const int a_max[2], std::function<bool (const int&)> callback) const;

    void RemoveAll();

    int Count();

    protected:

    struct Rect
    {
        int m_min[2];                      ///< Min dimensions of bounding box
        int m_max[2];                      ///< Max dimensions of bounding box
    };

    struct Branch
    {
        Rect m_rect;                                  ///< Bounds
        Node* m_child;                                ///< Child node
        int m_data;                              ///< Data Id
    };

    /// Node for each branch level
    struct Node
    {
        bool IsInternalNode()                         { return (m_level > 0); } // Not a leaf, but a internal node
        bool IsLeaf()                                 { return (m_level == 0); } // A leaf, contains data

        int m_count;                                  ///< Count
        int m_level;                                  ///< Leaf is zero, others positive
        Branch m_branch[MAXNODES];                    ///< Branch
    };

    struct ListNode
    {
        ListNode* m_next;                             ///< Next in list
        Node* m_node;                                 ///< Node
    };

    /// Variables for finding a split partition
    struct PartitionVars
    {
        enum { NOT_TAKEN = -1 }; // indicates that position

        int m_partition[MAXNODES+1];
        int m_total;
        int m_minFill;
        int m_count[2];
        Rect m_cover[2];
        float m_area[2];

        Branch m_branchBuf[MAXNODES+1];
        int m_branchCount;
        Rect m_coverSplit;
        float m_coverSplitArea;
    };

    Node* AllocNode();
    void FreeNode(Node* a_node);
    void InitNode(Node* a_node);
    void InitRect(Rect* a_rect);
    bool InsertRectRec(const Branch& a_branch, Node* a_node, Node** a_newNode, int a_level);
    bool InsertRect(const Branch& a_branch, Node** a_root, int a_level);
    Rect NodeCover(Node* a_node);
    bool AddBranch(const Branch* a_branch, Node* a_node, Node** a_newNode);
    void DisconnectBranch(Node* a_node, int a_index);
    int PickBranch(const Rect* a_rect, Node* a_node);
    Rect CombineRect(const Rect* a_rectA, const Rect* a_rectB);
    void SplitNode(Node* a_node, const Branch* a_branch, Node** a_newNode);
    float RectSphericalVolume(Rect* a_rect);
    float RectVolume(Rect* a_rect);
    float CalcRectVolume(Rect* a_rect);
    void GetBranches(Node* a_node, const Branch* a_branch, PartitionVars* a_parVars);
    void ChoosePartition(PartitionVars* a_parVars, int a_minFill);
    void LoadNodes(Node* a_nodeA, Node* a_nodeB, PartitionVars* a_parVars);
    void InitParVars(PartitionVars* a_parVars, int a_maxRects, int a_minFill);
    void PickSeeds(PartitionVars* a_parVars);
    void Classify(int a_index, int a_group, PartitionVars* a_parVars);
    bool RemoveRect(Rect* a_rect, const int& a_id, Node** a_root);
    bool RemoveRectRec(Rect* a_rect, const int& a_id, Node* a_node, ListNode** a_listNode);
    ListNode* AllocListNode();
    void FreeListNode(ListNode* a_listNode);
    bool Overlap(Rect* a_rectA, Rect* a_rectB) const;
    void ReInsert(Node* a_node, ListNode** a_listNode);
    bool Search(Node* a_node, Rect* a_rect, int& a_foundCount, std::function<bool (const int&)> callback) const;
    void RemoveAllRec(Node* a_node);
    void Reset();
    void CountRec(Node* a_node, int& a_count);

    Node* m_root;                                    ///< Root of tree
    float m_unitSphereVolume;                 ///< Unit sphere constant for required number of dimensions

    public:
    // return all the AABBs that form the RTree
    std::vector<Rect> ListTree() const;
    };

}
