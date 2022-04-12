#include "queues/UF.h"

namespace Drive::CPP17::UF{

    UF::UF(unsigned int n):count(n){
        parent = new unsigned[n]; 
        rank = new unsigned[n];
        for (unsigned int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        cout << "UF cons" << endl;
    }

    UF::~UF(){
        delete [] parent;
        delete [] rank;

        cout << "UF des" << endl;
    }
    
    bool UF::connected_Query(int i, int j){
        return find(i) == find(j);
    }

    void UF::union_Command(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make root of smaller rank point to root of larger rank
        if      (rank[rootP] < rank[rootQ]){
            parent[rootP] = rootQ;
        } 
        else if (rank[rootP] > rank[rootQ]){
            parent[rootQ] = rootP;
        } 
        else {
            parent[rootQ] = rootP;
            rank[rootP] = rank[rootP] + 1;
        }
        count--;
    }

    int UF::find(int p){
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    // path compression by halving
            p = parent[p];
        }
        return p;
    }

    int UF::count_items(){
        return count;
    }

}