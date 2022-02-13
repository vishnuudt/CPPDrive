#pragma once

#include <iostream>

using namespace std;


namespace Drive::CPP17::Graphs{

class FlowEdge{
public:

    FlowEdge() = delete;

    FlowEdge(int v, int w, double capacity);

    virtual ~FlowEdge();

    FlowEdge(const FlowEdge& );

    FlowEdge(const FlowEdge&& );

    FlowEdge& operator=(const FlowEdge& );

    FlowEdge& operator=(const FlowEdge&& );

    int from();

    int to();

    double capacity();

    double flow();

    int other(int vertex);

    double residualCapacityTo(int vertex);

    void addResidualFlowTo(int vertex, double delta);

private:
    unsigned int v{};
    unsigned int w{};
    double capacty{};
    double flo{};


};
}