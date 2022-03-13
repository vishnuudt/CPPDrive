#include "trees/TwoThree.h"

using namespace std;

namespace Drive::CPP17::Trees{

    TwoThreeTree::TwoThreeTree(){
        std::cout << "cons TwoThreeTree" << std::endl;
    }

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
        if (!h) return std::move(std::make_unique<Node>(key, val, Node::RED, 1));

        int cmp = key.compare(h->key);
        if      (cmp < 0) h->left  = put(h->left,  key, val); 
        else if (cmp > 0) h->right = put(h->right, key, val); 
        else              h->value   = val;

        // fix-up any right-leaning links
        if (isRed(h->right) && !isRed(h->left)){
            h = rotateLeft(h);
        }      
        if (isRed(h->left)  &&  isRed(h->left->left)){
            h = rotateRight(h);
        } 
        if (isRed(h->left)  &&  isRed(h->right)) {
            flipColors(h);
        } 

        h->size = count(h->left) + count(h->right) + 1;

        return std::move(h);
    }


    NodeUniqPtr TwoThreeTree::rotateRight(NodeUniqPtr& me) {
        // assert (h != null) && isRed(h.left);
        // assert (h != null) && isRed(h.left) &&  !isRed(h.right);  // for insertion only
        Node* mine = me.release();
        Node* myLeft = mine->left.release();
        Node* myLeftsRight = myLeft->right.release();
        
        mine->left.reset(myLeftsRight);
        myLeft->right.reset(mine);
        myLeft->color = myLeft->right->color;
        myLeft->right->color = Node::RED;
        myLeft->size = mine->size;
        mine->size = count(mine->left) + count(mine->right) + 1;

        return NodeUniqPtr(myLeft);
    }

    // make a right-leaning link lean to the left
    NodeUniqPtr TwoThreeTree::rotateLeft(NodeUniqPtr& me) {
        // assert (h != null) && isRed(h.right);
        // assert (h != null) && isRed(h.right) && !isRed(h.left);  // for insertion only
        Node* mine = me.release();
        Node* myRight = mine->right.release();
        Node* myRightsLeft = myRight->left.release();
              
        // NodeUniqPtr&& x = std::move(h->right);
        mine->right.reset(myRightsLeft);
        myRight->left.reset(mine);
        myRight->color = myRight->left->color;
        myRight->left->color = Node::RED;
        myRight->size = mine->size;
        mine->size = count(mine->left) + count(mine->right) + 1;

        return NodeUniqPtr(myRight);
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
        if (!x) return false;
        return x->color == Node::RED;
    }

    int TwoThreeTree::count(NodeUniqPtr& y) {
        if (!y) return 0;
        return y->size;
    } 


    queue<string> TwoThreeTree::keys(string lo, string hi) {
  
        queue<string> queue;
        // if (isEmpty() || lo.compareTo(hi) > 0) return queue;
        keys(root, queue, lo, hi);
        return queue;
    } 

    // add the keys between lo and hi in the subtree rooted at x
    // to the queue
    void TwoThreeTree::keys(NodeUniqPtr& x, queue<string>& qu, string lo, string hi) { 
        if (!x) return; 
        int cmplo = lo.compare(x->key); 
        int cmphi = hi.compare(x->key); 
        if (cmplo < 0) keys(x->left, qu, lo, hi); 
        if (cmplo <= 0 && cmphi >= 0) qu.push(x->key); 
        if (cmphi > 0) keys(x->right, qu, lo, hi); 
    } 


    void TwoThreeTree::exportItem(){
        TwoThreeTree leftLeaningRebBlackTree;
        string keys[]{ "S", "E", "A", "R", "C", "H", "E", "X", "A", "M", "P", "L", "E"};
        int i = 0;
        
        for (auto& key : keys) {
            leftLeaningRebBlackTree.put(key, ++i);
        }
    
        queue<string> queuekeys = leftLeaningRebBlackTree.keys("A", "Z");
        while (!queuekeys.empty()) {
            string key = queuekeys.front();
            cout << "key:" << key << " value:" 
                 << leftLeaningRebBlackTree.get(key) << endl;
            queuekeys.pop();
        }
    }
}