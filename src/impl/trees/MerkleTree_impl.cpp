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

    void MerkleTree::exportItem(){
        cout << "I am merkle" << endl;
    }

}