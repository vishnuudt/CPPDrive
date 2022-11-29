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

    unique_ptr<MerkleNode> MerkleTree::build(vector<string>& values){
        return nullptr;
    }

    unique_ptr<MerkleNode> MerkleTree::addLeaf(unique_ptr<MerkleNode>& root, 
    string& value){
        return nullptr;
    }

    void MerkleTree::exportItem(){
        hash<string> h;
        const size_t value = h("vishnu");
        cout << value << endl;
    }

    size_t MerkleNode::computeHash(){

        return 0;
    }
    
    bool MerkleNode::validate() const{
        return true;
    }

    MerkleNode::MerkleNode(){
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