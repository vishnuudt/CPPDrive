#include <iostream>
#include <string.h>
#include "queues/Index_MinPQ.h"
#include "CPP-17_features.h"
#include "graphs/Flow_Network.h"
#include "trees/TwoThree.h"
#include "strings/StringSearch.h"

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

        KnuthMorrisPratt kmp;
        kmp.search("1234", "23");
    }
}