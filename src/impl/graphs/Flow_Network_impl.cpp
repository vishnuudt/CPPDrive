#include "graphs/Flow_Network.h"

using namespace std;

namespace Drive::CPP17::Graphs{

    FlowNetwork::FlowNetwork(int v, int e):num_vertices(v), 
    num_edges(e), vect_FlowEdgeLists{v, fListFlowEdges(e)}
    {
        for (int i = 0 ; i < num_vertices; ++i){
            auto& list = vect_FlowEdgeLists[i];
            list.clear();
        }
    }

    FlowNetwork::~FlowNetwork(){

    }

    FlowNetwork::FlowNetwork(const FlowNetwork& ){

    }

    FlowNetwork::FlowNetwork(const FlowNetwork&& ){

    }

    FlowNetwork& FlowNetwork::operator=(const FlowNetwork& ){
        return *this;    
    }

    FlowNetwork& FlowNetwork::operator=(const FlowNetwork&& ){
        return *this;
    }

    void FlowNetwork::addEdge(FlowEdgesharedPtr& edgePtr){
        int v = edgePtr->from();
        int w = edgePtr->to();
        if ((v < 0 || v >= num_vertices) || (w < 0 || w >= num_vertices)){
            cerr << "bad item" << endl;
            return;
        }
        vect_FlowEdgeLists[v].push_back(edgePtr);
        vect_FlowEdgeLists[w].push_back(edgePtr);
        num_edges++;
    }

    fListFlowEdges& FlowNetwork::adj(int v){
        return vect_FlowEdgeLists[v];
    }

    fListFlowEdges FlowNetwork::edges(){
        fListFlowEdges flowEdges;
        for (int v = 0; v < num_vertices; v++)
            for (const auto& item : adj(v)) {
                if (item->to() != v){
                    flowEdges.push_back(item);
                }      
            }
        return flowEdges;
    }

    void FlowNetwork::exportItem(){
        FlowNetwork f_Network(6, 8);
        FlowEdgesharedPtr edge1 = std::make_shared<FlowEdge>(0, 1, 2.0);
        FlowEdgesharedPtr edge2 = std::make_shared<FlowEdge>(0, 2, 3.0);
        FlowEdgesharedPtr edge3 = std::make_shared<FlowEdge>(1, 3, 3.0);
        FlowEdgesharedPtr edge4 = std::make_shared<FlowEdge>(1, 4, 1.0);
        FlowEdgesharedPtr edge5 = std::make_shared<FlowEdge>(2, 3, 1.0);
        FlowEdgesharedPtr edge6 = std::make_shared<FlowEdge>(2, 4, 1.0);
        FlowEdgesharedPtr edge7 = std::make_shared<FlowEdge>(3, 5, 2.0);
        FlowEdgesharedPtr edge8 = std::make_shared<FlowEdge>(4, 5, 3.0);
        f_Network.addEdge(edge1);
        f_Network.addEdge(edge2);
        f_Network.addEdge(edge3);
        f_Network.addEdge(edge4);
        f_Network.addEdge(edge5);
        f_Network.addEdge(edge6);
        f_Network.addEdge(edge7);
        f_Network.addEdge(edge8);

        for (const auto& item: f_Network.edges()){
            cout << item->toString() << endl;
        }





    }
}