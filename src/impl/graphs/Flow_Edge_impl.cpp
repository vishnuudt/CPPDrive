#include "graphs/Flow_Edge.h"

using namespace std;

namespace Drive::CPP17::Graphs{

FlowEdge::FlowEdge(int v, int w, double capa): v(v), w(w), capacty(capa){
    std::cout << "cons FlowEdge" << std::endl;
}

FlowEdge::~FlowEdge(){
    std::cout << "des FlowEdge" << std::endl;
}

FlowEdge::FlowEdge(const FlowEdge& ){
    std::cout << "copy cons lval FlowEdge" << std::endl;
}

FlowEdge::FlowEdge(const FlowEdge&& ){
    std::cout << "copy cons rval FlowEdge" << std::endl;
}

FlowEdge& FlowEdge::operator=(const FlowEdge& ){
     std::cout << "assign lval FlowEdge" << std::endl;
     return *this;
}

FlowEdge& FlowEdge::operator=(const FlowEdge&& ){
    std::cout << " assign rval FlowEdge" << std::endl;
    return *this;
}

int FlowEdge::from(){
    return v;
}

int FlowEdge::to(){
    return w;
}

double FlowEdge::capacity(){
    return capacty;
}

double FlowEdge::flow(){
    return flo;
}

int FlowEdge::other(int vertex){
    if (vertex == v) return w;
    else if (vertex == w) return v;
    cerr << "wrong expectation other" << endl;
    return -100;
}

double FlowEdge::residualCapacityTo(int vertex){
    if (vertex == v) return flo;
    if (vertex == w) return capacty - flo;
    cerr << "wrong expectation residualCapacityTo" << endl;
    return -100.0;
}

void FlowEdge::addResidualFlowTo(int vertex, double delta){
    if (vertex == v) flo -= delta;
    if (vertex == w) flo += delta;
    cerr << "wrong expectation addResidualFlowTo" << endl;
}

}

