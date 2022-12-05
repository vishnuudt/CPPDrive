#include "trees/MerkleTree.h"

using namespace std;

namespace Drive::CPP17::Trees{

    MerkleTree::MerkleTree(){
        std::cout << "cons MerkleTree" << std::endl;
    }

    MerkleTree::~MerkleTree(){
        std::cout << "des MerkleTree" << std::endl;
    }

    MerkleTree::MerkleTree(const MerkleTree& ){
        std::cout << "copy cons lval MerkleTree" << std::endl;
    }

    MerkleTree::MerkleTree(const MerkleTree&& ){
        std::cout << "copy cons rval MerkleTree" << std::endl;
    }

    MerkleTree& MerkleTree::operator=(const MerkleTree& ){
        std::cout << "assign lval MerkleTree" << std::endl;
        return *this;
    }

    MerkleTree& MerkleTree::operator=(const MerkleTree&& ){
        std::cout << " assign rval MerkleTree" << std::endl;
        return *this;
    }

    unique_ptr<MerkleNode>& MerkleTree::build(vector<string>& values){
        string first = values.at(0);
        root = make_unique<MerkleNode>(first, nullptr, nullptr);
        for (auto&& item : values){
            root = addLeaf(root, item);
        }
        return root;
    }

    unique_ptr<MerkleNode> MerkleTree::addLeaf(unique_ptr<MerkleNode>& root, 
    string& value){
        auto&& uniqMerkleNodePtr = make_unique<MerkleNode>(value, std::move(root), nullptr);
        return uniqMerkleNodePtr;
    }

    bool MerkleTree::validate(){
        if(root){
            root->validate();
        }
        return true;
    }

    void MerkleTree::exportItem(){
        vector<string> values{"a", "b", "c", "d"};
        MerkleTree mTree;
        mTree.build(values);
        mTree.validate();
    }



    size_t MerkleNode::computeHash(){
        hash_val = h(value_val);
        return hash_val;
    }
    
    bool MerkleNode::validate() const{
        cout << "value is:" 
        << value_val << " " 
        << "hash is:" << hash_val << endl;
        if (left){
            left->validate();
        }
        if (right){
            right->validate();
        }
        return true;
    }

    MerkleNode::MerkleNode(string w, 
        unique_ptr<MerkleNode> left_, 
        unique_ptr<MerkleNode> right_): value_val(w){
        computeHash();
        if (left_){
            left = std::move(left_);
            left->computeHash();
        }
        if(right_){
            right = std::move(right_);
            right->computeHash();
        }
        std::cout << "cons MerkleNode" << std::endl;
    }

    MerkleNode::~MerkleNode(){
        std::cout << "des MerkleNode" << std::endl;
    }

    MerkleNode::MerkleNode(const MerkleNode& ){
        std::cout << "copy cons lval MerkleNode" << std::endl;
    }

    MerkleNode::MerkleNode(const MerkleNode&& ){
        std::cout << "copy cons rval MerkleNode" << std::endl;
    }

    MerkleNode& MerkleNode::operator=(const MerkleNode& ){
        std::cout << "assign lval MerkleNode" << std::endl;
        return *this;
    }

    MerkleNode& MerkleNode::operator=(const MerkleNode&& ){
        std::cout << " assign rval MerkleNode" << std::endl;
        return *this;
    }

}