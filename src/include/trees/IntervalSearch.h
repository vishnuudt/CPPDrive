#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

namespace Drive::CPP17::Trees{


class Interval2D{
public:
    Interval2D(double mi, double ma);
    ~Interval2D();
    bool isIntersect(const Interval2D& that);
    double getMin() const;
    double getMax() const;

private:
    const double min;
    const double max;

};

class IntervalNode{
    public:
        IntervalNode(Interval2D interval);
        ~IntervalNode();
        IntervalNode* left;
        IntervalNode* right;
        Interval2D interval;
        double max;

    private:

};  

class IntervalSearchTree{
    public:
     bool search(const Interval2D& item);
     void put(Interval2D& item);
     void all();
     static void exportItem();   



    private:
        unique_ptr<IntervalNode> top_root;
        IntervalNode* put(IntervalNode* root, Interval2D& item);
        void all(IntervalNode* root);



};

}