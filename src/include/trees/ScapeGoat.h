#pragma once

#include <iostream>
#include <memory>
#include "Node.h"

using namespace std;

namespace Drive::CPP17::Trees{

    using NodeUnitPtrArr = std::unique_ptr<NodeUniqPtr>;

    class ScapeGoatTree {

    public:
        int rebalance(NodeUniqPtr ptr);
        void serializeAsArray(NodeUniqPtr root, NodeUnitPtrArr arr, int index);

        static void exportItem();

    };

}