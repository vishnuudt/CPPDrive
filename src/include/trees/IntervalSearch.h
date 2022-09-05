#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

namespace Drive::CPP17::Trees{


class Interval2D{
public:
    Interval2D(double mi, double ma);
    bool isIntersect(Interval2D& that);
    double getMin();
    double getMax();

private:
    const double min;
    const double max;

};

class IntervalNode{
    public:
        IntervalNode(Interval2D interval);
        IntervalNode* left;
        IntervalNode* right;
        Interval2D interval;
        double max;

    private:

};  

class IntervalSearchTree{
    public:
     bool search(Interval2D& item);
     void put(Interval2D& item);
     void all();
     static void exportItem();   



    private:
        unique_ptr<IntervalNode> top_root;
        IntervalNode* put(IntervalNode* root, Interval2D& item);
        void all(IntervalNode* root);



};

}