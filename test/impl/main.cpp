#include <iostream>
#include <string.h>
#include "queues/Index_MinPQ.h"
#include "CPP-17_features.h"
#include "graphs/Flow_Network.h"
#include "trees/TwoThree.h"
#include "strings/StringSearch.h"
#include "graphs/Traversal_paths.h"

using namespace std;
using namespace Drive::CPP17;
using namespace Drive::IndexedMinPQ;
using namespace Drive::CPP17::Graphs;
using namespace Drive::CPP17::Trees;
using namespace Drive::strings;

int main(int args, char** argv){
    {
        // CPP17Features features;
        // features.exportItem();
    }

    {
        // IndexedMinPQ::exportItem();

    }

    {
        // FlowNetwork::exportItem();
    }

    {
        //TwoThreeTree::exportItem();
    }

    {
        //StringSearch ss;
        //ss.search("one", "oneone");

        //KnuthMorrisPratt kmp;
        //kmp.search("122334455443", "344");
    }

    {
        FlowNetwork&& g = FlowNetwork::exportItem();
        DFS dfs(g, 0);
        cout << "haspath:" << dfs.hasPathTo(3) << endl;
        cout << "path:";
        for (auto item: dfs.pathTo(3)){
             cout << item << " :: ";
        }
        cout << endl;  

        BFS traverse(g, 0);
        cout << "haspath:" << traverse.hasPathTo(5) << endl;
        cout << "path:";
        for (auto item: traverse.pathTo(5)){
             cout << item << " at distance:" << traverse.distToVertex(item) << " :: ";
        }
        cout << endl;        

    }
}