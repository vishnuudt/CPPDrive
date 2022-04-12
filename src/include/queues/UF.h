#pragma once 

#include <iostream>

using namespace std;

namespace Drive::CPP17::UF{

    class UF{
        public:
            UF(unsigned int n);
            ~UF();
            bool connected_Query(int i, int j);
            void union_Command(int i, int j);
            int find(int i);
            int count_items();



        private:
            unsigned int* parent;  // parent[i] = parent of i
            unsigned int* rank;   // rank[i] = rank of subtree rooted at i (never more than 31)
            int count;     // number of components
    };

}