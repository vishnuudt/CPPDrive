#include "trees/TwoThree.h"

namespace Drive::CPP17::Trees{


    TwoThreeTree::~TwoThreeTree(){
        std::cout << "des TwoThreeTree" << std::endl;
    }

    TwoThreeTree::TwoThreeTree(const TwoThreeTree& ){
        std::cout << "copy cons lval TwoThreeTree" << std::endl;
    }

    TwoThreeTree::TwoThreeTree(const TwoThreeTree&& ){
        std::cout << "copy cons rval TwoThreeTree" << std::endl;
    }

    TwoThreeTree& TwoThreeTree::operator=(const TwoThreeTree& ){
        std::cout << "assign lval TwoThreeTree" << std::endl;
        return *this;
    }

    TwoThreeTree& TwoThreeTree::operator=(const TwoThreeTree&& ){
        std::cout << " assign rval TwoThreeTree" << std::endl;
        return *this;
    }

    int TwoThreeTree::get(string key) {
        Node* x = root.get();
        while (x) {
            int cmp = key.compare(x->key);
            if      (cmp < 0) x = x->left.get();
            else if (cmp > 0) x = x->right.get();
            else  return x->value;
        }
        return -1;
    }

     void TwoThreeTree::put(string key, int val) {


        root = put(root, key, val);
        root->color = Node::BLACK;
        // assert check();
    }

    NodeUniqPtr TwoThreeTree::put(NodeUniqPtr& h, string key, int val) { 
        if (!h) return std::make_unique<Node>(key, val, Node::RED, 1);

        int cmp = key.compare(h->key);
        if      (cmp < 0) h->left  = put(h->left,  key, val); 
        else if (cmp > 0) h->right = put(h->right, key, val); 
        else              h->value   = val;

        // fix-up any right-leaning links
        if (isRed(h->right) && !isRed(h->left))      h = rotateLeft(h);
        if (isRed(h->left)  &&  isRed(h->left->left)) h = rotateRight(h);
        if (isRed(h->left)  &&  isRed(h->right))     flipColors(h);
        h->size = count(h->left) + count(h->right) + 1;

        return std::move(h);
    }


    NodeUniqPtr TwoThreeTree::rotateRight(NodeUniqPtr& h) {
        // assert (h != null) && isRed(h.left);
        // assert (h != null) && isRed(h.left) &&  !isRed(h.right);  // for insertion only
        NodeUniqPtr&& x = std::move(h->left);
        h->left = std::move(x->right);
        x->right = std::move(h);
        x->color = x->right->color;
        x->right->color = Node::RED;
        x->size = h->size;
        h->size = count(h->left) + count(h->right) + 1;
        return std::move(x);
    }

    // make a right-leaning link lean to the left
    NodeUniqPtr TwoThreeTree::rotateLeft(NodeUniqPtr& h) {
        // assert (h != null) && isRed(h.right);
        // assert (h != null) && isRed(h.right) && !isRed(h.left);  // for insertion only
        NodeUniqPtr&& x = std::move(h->right);
        h->right = std::move(x->left);
        x->left = std::move(h);
        x->color = x->left->color;
        x->left->color = Node::RED;
        x->size = h->size;
        h->size = count(h->left) + count(h->right) + 1;
        return std::move(x);
    }

    // flip the colors of a node and its two children
    void TwoThreeTree::flipColors(NodeUniqPtr& h) {
        // h must have opposite color of its two children
        // assert (h != null) && (h.left != null) && (h.right != null);
        // assert (!isRed(h) &&  isRed(h.left) &&  isRed(h.right))
        //    || (isRed(h)  && !isRed(h.left) && !isRed(h.right));
        h->color = !h->color;
        h->left->color = !h->left->color;
        h->right->color = !h->right->color;
    }


    bool TwoThreeTree::isRed(NodeUniqPtr& x) {
        return x->color == Node::RED;
    }

    int TwoThreeTree::count(NodeUniqPtr& y) {
        return y->size;
    } 


    void TwoThreeTree::exportItem(){

    }

}