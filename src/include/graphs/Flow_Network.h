#pragma once

#include <iostream>
#include <algorithm>
#include <forward_list>
#include <memory>
#include "Flow_Edge.h"

using namespace std;

namespace Drive::CPP17::Graphs{

    using FlowEdgesharedPtr = std::shared_ptr<FlowEdge>;
    using fListFlowEdges = std::vector<FlowEdgesharedPtr>;

    class FlowNetwork{
    public:
        FlowNetwork() = delete;

        FlowNetwork(int v, int e);

        virtual ~FlowNetwork();

        FlowNetwork(const FlowNetwork& );

        FlowNetwork(const FlowNetwork&& );

        FlowNetwork& operator=(const FlowNetwork& );

        FlowNetwork& operator=(const FlowNetwork&& );

        void addEdge(FlowEdgesharedPtr& edgePtr);

        fListFlowEdges& adj(int v);

        fListFlowEdges edges(); 

        int numVertices();

        static FlowNetwork exportItem();

    private:
        int num_vertices{0};
        int num_edges{0};
        std::vector<fListFlowEdges> vect_FlowEdgeLists{};

    };

}

