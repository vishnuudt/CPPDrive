#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

namespace Drive::CPP17::Trees{


class MerkleNode {
 public:
    unique_ptr<MerkleNode> left;
    unique_ptr<MerkleNode> right;
    size_t hash;
    string value;

 public:
    virtual size_t computeHash(); 
    virtual bool validate() const;

    MerkleNode();

    virtual ~MerkleNode();

    MerkleNode(const MerkleNode& );

    MerkleNode(const MerkleNode&& );

    MerkleNode& operator=(const MerkleNode& );

    MerkleNode& operator=(const MerkleNode&& );


};

class MerkleTree {
    public:

    MerkleTree();

    virtual ~MerkleTree();

    MerkleTree(const MerkleTree& );

    MerkleTree(const MerkleTree&& );

    MerkleTree& operator=(const MerkleTree& );

    MerkleTree& operator=(const MerkleTree&& );

    unique_ptr<MerkleNode> build(vector<string>& values);

    unique_ptr<MerkleNode> addLeaf(unique_ptr<MerkleNode>& root, string& value);

    static void exportItem();

    private: 
        unique_ptr<MerkleNode> root;
};

}