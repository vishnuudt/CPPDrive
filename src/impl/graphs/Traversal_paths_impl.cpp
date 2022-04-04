#include "graphs/Traversal_paths.h"

namespace Drive::CPP17::Graphs{

    DFS::DFS(FlowNetwork& g, int v):source{v}{
        int count = g.numVertices();
        marked = new bool[count]{};
        edgeTo = new int[count]{}; 
        traverse(g, source);
    }

    bool DFS::hasPathTo(int w){
        return marked[w];
    }

    vector<int> DFS::pathTo(int w){
        vector<int> path;
        if (!hasPathTo(w)) {
            return path;
        }
        
        for (int x = w; x != source; x = edgeTo[x]){
            path.push_back(x);
        }            
        path.push_back(source);
        return path;
    }

    void DFS::traverse(FlowNetwork& G, int v) {
        marked[v] = true;
        for (auto&& item : G.adj(v)) {
            auto toVertex = item->to();
            if (!marked[toVertex]) {
                edgeTo[toVertex] = v;
                traverse(G, toVertex);
            }
        }
    }



}