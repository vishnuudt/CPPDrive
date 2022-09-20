#include "trees/IntervalSearch.h"

namespace Drive::CPP17::Trees {

    Interval2D::Interval2D(double mi, double ma):min(mi), max{ma}{
        if (mi > ma){
            throw invalid_argument("min should be less than max");
        }
        cout << "Interval 2D cons" << endl;
    }

    Interval2D::~Interval2D(){
        cout << "Interval 2D des" << endl;
    }

    bool Interval2D::isIntersect(const Interval2D& that){
        if ((this->max < that.min)  ||  that.max < this->min ){
            return false;
        }
        return true;
    }

    double Interval2D::getMin() const {
        return min;
    }

    double Interval2D::getMax() const {
        return max;
    }


    IntervalNode::IntervalNode(Interval2D item):interval(item){
        cout << "IntervalNode cons" << endl;
    }

    IntervalNode::~IntervalNode(){
        delete left;
        delete right;
        cout << "IntervalNode des" << endl;
    }

    bool IntervalSearchTree::search(const Interval2D& item){
        IntervalNode* x = top_root.get();

        while(x != nullptr){
            if (x->interval.isIntersect(item)){
                return true;
            }else if (x->left == nullptr){
                x = x->right;
            }else if (x->left->max < item.getMin()){
                x = x->right;
            }else {
                x = x->left;
            }
        }
        return false;

    }


    void IntervalSearchTree::put(Interval2D& item){
        IntervalNode* temp = put(top_root.get(), item);
        if (top_root == nullptr){
            top_root = std::unique_ptr<IntervalNode>(temp);
        }
    }

    IntervalNode* IntervalSearchTree::put(IntervalNode* root, Interval2D& i){
        // Base case: Tree is empty, new node becomes root
        if (root == nullptr)
            return new IntervalNode(i);
    
        // Get low value of interval at root
        int l = root->interval.getMin();
    
        // If root's low value is smaller, then new interval goes to
        // left subtree
        if (i.getMin() < l)
            root->left = put(root->left, i);
    
        // Else, new node goes to right subtree.
        else
            root->right = put(root->right, i);
    
        // Update the max value of this ancestor if needed
        if (root->max < i.getMax())
            root->max = i.getMax();
    
        return root;
    }

    void IntervalSearchTree::all(){
        if (top_root == nullptr) return;
        all(top_root.get());

    }

    void IntervalSearchTree::all(IntervalNode* root){
        if (root == nullptr){
            return;
        }

        all(root->left);
    
        cout << "[" << root->interval.getMin() << ", " << root->interval.getMax() << "]"
            << " max = " << root->max << endl;
    
        all(root->right);
    }



    void IntervalSearchTree::exportItem(){
        Interval2D one(7, 10);
        Interval2D two(5, 8);
        Interval2D three(17, 19);
        Interval2D four(21, 24);

        IntervalSearchTree ist;
        ist.put(one);
        ist.put(two);
        ist.put(three);
        ist.put(four);

        ist.all();
        bool result = ist.search(Interval2D(6,9));
        cout << "searching (6,9): " << result;

        result = ist.search(Interval2D(24, 30));
        cout << "searching (6,9): " << result;

    }

}