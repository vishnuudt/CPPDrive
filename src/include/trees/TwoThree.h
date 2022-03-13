#pragma once

#include <iostream>
#include <string>
#include <queue>

#include "trees/Node.h"

using namespace std;

namespace Drive::CPP17::Trees{

class TwoThreeTree{
public:
        TwoThreeTree();

        virtual ~TwoThreeTree();

        TwoThreeTree(const TwoThreeTree& );

        TwoThreeTree(const TwoThreeTree&& );

        TwoThreeTree& operator=(const TwoThreeTree& );

        TwoThreeTree& operator=(const TwoThreeTree&& );

        int get(string key);

        void put(string key, int value);

        queue<string> keys(string lo, string hi);

        static void exportItem();

private:
    NodeUniqPtr root;

    NodeUniqPtr put(NodeUniqPtr& h, string key, int value);

    NodeUniqPtr rotateRight(NodeUniqPtr& h);
    NodeUniqPtr rotateLeft(NodeUniqPtr& h);
    void flipColors(NodeUniqPtr& h);

    bool isRed(NodeUniqPtr& x);
    int count(NodeUniqPtr& x);

    void keys(NodeUniqPtr& x, queue<string>& queue, 
              string lo, string hi); 

};
}