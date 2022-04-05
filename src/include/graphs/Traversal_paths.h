#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "Flow_Network.h"

using namespace std;

namespace Drive::CPP17::Graphs{

    class DFS{

        public:
            DFS(FlowNetwork& G, int v);
            ~DFS();
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
        public:
            BFS(FlowNetwork& G, int w);
            ~BFS();
            bool hasPathTo(int w);
            vector<int> pathTo(int w);
            int distToVertex(int v);

        private:
            bool* marked;
            int* edgeTo;
            float* distTo;


            void traverse(FlowNetwork& g, int w);


    };
}