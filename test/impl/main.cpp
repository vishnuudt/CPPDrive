#include <iostream>
#include <string.h>
#include <memory>
#include "queues/Index_MinPQ.h"
#include "queues/UF.h"
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
using namespace Drive::CPP17::UF;

CPP17Features createCPP17Features(int size)
{
  return CPP17Features(size);
}


int main(int args, char** argv){
    {
        CPP17Features h1(1000);                // regular constructor
        CPP17Features h2(h1);                  // copy constructor (lvalue in input)
        CPP17Features h3 = createCPP17Features(2000); // move constructor (rvalue in input) (1) 

        h2 = h3;                        // assignment operator (lvalue in input)
        h2 = createCPP17Features(500);         // move assignment operator (rvalue in input)
        CPP17Features h4(std::move(h2));
        
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
        /*
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
        */
    }


    {
        /*
        unique_ptr<Drive::CPP17::UF::UF> uf = make_unique<Drive::CPP17::UF::UF>(10);
        uf->union_Command(4, 3);
        uf->union_Command(3, 8);
        uf->union_Command(6, 5);
        uf->union_Command(9, 4);
        uf->union_Command(2, 1);
        uf->union_Command(8, 9);
        uf->union_Command(5, 0);
        uf->union_Command(7, 2);
        uf->union_Command(6, 1);
        uf->union_Command(1, 0);
        uf->union_Command(6, 7);
        uf->connected_Query(4, 9);

        cout << "total count:" << uf->count_items() << endl;
        */

    }
}