#include <queue>
#include "graphs/Traversal_paths.h"

namespace Drive::CPP17::Graphs{

    DFS::DFS(FlowNetwork& g, int v):source{v}{
        int count = g.numVertices();
        marked = new bool[count]{};
        edgeTo = new int[count]{}; 
        traverse(g, source);
        cout << "DFS cons" << endl;
    }

    DFS::~DFS(){
        delete [] marked;
        delete [] edgeTo;
        cout << "DFS des" << endl;
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

    /*  BFS impl starts  */


    BFS::BFS(FlowNetwork& g, int source){
        int count = g.numVertices();
        marked = new bool[count]{};
        edgeTo = new int[count]{}; 
        distTo = new float[count]{};
        traverse(g, source);
        cout << "BFS cons" << endl;
    }

    BFS::~BFS(){
        delete [] marked;
        delete [] edgeTo;
        delete [] distTo;
        cout << "BFS des" << endl;

    }

    void BFS::traverse(FlowNetwork& g, int s){
        queue<int> q;
        for (int v = 0; v < g.numVertices(); v++)
            distTo[v] = INFINITY;
        distTo[s] = 0;
        marked[s] = true;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto&& item : g.adj(v)) {
                auto toVertex = item->to();
                if (!marked[toVertex]) {
                    edgeTo[toVertex] = v;
                    distTo[toVertex] = distTo[v] + 1;
                    marked[toVertex] = true;
                    q.push(toVertex);
                }
            }
        }
    }

    bool BFS::hasPathTo(int w){
        return marked[w];
    }

    vector<int> BFS::pathTo(int w){
        vector<int> path;
        if (!hasPathTo(w)) {
            return path;
        }
        
        int x;
        for (x = w; distTo[x] != 0; x = edgeTo[x]){
            path.push_back(x);
        }         
        path.push_back(x);
        return path;
    }

    int BFS::distToVertex(int w){
        return distTo[w];
    }   


}