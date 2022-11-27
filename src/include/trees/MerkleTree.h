#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

namespace Drive::CPP17::Trees{


class MerkleTree {
    public:

    MerkleTree();

    virtual ~MerkleTree();

    MerkleTree(const MerkleTree& );

    MerkleTree(const MerkleTree&& );

    MerkleTree& operator=(const MerkleTree& );

    MerkleTree& operator=(const MerkleTree&& );

    static void exportItem();

    private:

};


}