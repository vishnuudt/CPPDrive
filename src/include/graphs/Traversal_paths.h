#pragma once

#include <iostream>
#include <vector>
#include "Flow_Network.h"

using namespace std;

namespace Drive::CPP17::Graphs{

    class DFS{

        public:
            DFS(FlowNetwork& G, int v);
            bool hasPathTo(int w);
            vector<int> pathTo(int w);


        private:
            bool* marked;    // marked[v] = is there an s-v path?
            int* edgeTo;        // edgeTo[v] = last edge on s-v path
            const int source;         // source vertex
            

            // members
            void traverse(FlowNetwork& g, int w);
    };



    class BFS{


    };
}