#include "lists/SkipLists.h"

namespace Drive::CPP17::Lists{

    SkipLists::SkipLists():n{}, h{}{
        std::cout << "cons SkipLists" << std::endl;
    }

    SkipLists::~SkipLists(){
        std::cout << "des SkipLists" << std::endl;
    }

    SkipLists::SkipLists(const SkipLists& ){
        std::cout << "copy cons lval SkipLists" << std::endl;
    }

    SkipLists::SkipLists(const SkipLists&& ){
        std::cout << "copy cons rval SkipLists" << std::endl;
    }

    SkipLists& SkipLists::operator=(const SkipLists& ){
        std::cout << "assign lval SkipLists" << std::endl;
        return *this;
    }

    SkipLists& SkipLists::operator=(const SkipLists&& ){
        std::cout << " assign rval SkipLists" << std::endl;
        return *this;
    }

    void SkipLists::exportItem(){
        SkipLists skips;
    }

    string SkipLists::get(int i) {
        return findPred(i)->next[0]->x;
    }

    string SkipLists::set(int i, string x) {
        SkipListNode *u = findPred(i)->next[0];
        string y = u->x;
        u->x = x;
        return y;
    }

    void SkipLists::add(int i, string x) {
        SkipListNode *w = newNode(x, pickHeight());
        if (w->height > h)
        h = w->height;
        add(i, w);
    }

   string SkipLists::remove(int i) {
    string x;
    SkipListNode *u = sentinel;
    SkipListNode *del;
    int r = h;
    int j = -1; // index of node u
    while (r >= 0) {
        while (u->next[r] != NULL && j + u->length[r] < i) {
            j += u->length[r];
            u = u->next[r];
        }
        u->length[r]--; // for the node we are removing
        if (j + u->length[r] + 1 == i && u->next[r] != NULL) {
            x = u->next[r]->x;
            u->length[r] += u->next[r]->length[r];
            del = u->next[r];
            u->next[r] = u->next[r]->next[r];
            if (u == sentinel && u->next[r] == NULL)
            h--;
        }
        r--;
    }
    deleteNode(del);
    n--;
    return x;
  }

  int SkipLists::pickHeight() {
    int z = rand();
    int k = 0;
    int m = 1;
    while ((z & m) != 0) {
      k++;
      m <<= 1;
    }
    return k;
  }

    SkipListNode* SkipLists::findPred(int i) {
        SkipListNode *u = sentinel;
        int r = h;
        int j = -1;   // the index of the current node in list 0
        while (r >= 0) {
            while (u->next[r] != nullptr && j + u->length[r] < i) {
                j += u->length[r];
                u = u->next[r];
            }
            r--;
        }
        return u;
    }

    SkipListNode* SkipLists::add(int i, SkipListNode *w) {
        SkipListNode *u = sentinel;
        int k = w->height;
        int r = h;
        int j = -1; // index of u
        while (r >= 0) {
            while (u->next[r] != NULL && j + u->length[r] < i) {
                j += u->length[r];
                u = u->next[r];
            }
            u->length[r]++; // to account for new node in list 0
            if (r <= k) {
                w->next[r] = u->next[r];
                u->next[r] = w;
                w->length[r] = u->length[r] - (i - j);
                u->length[r] = i - j;
            }
            r--;
        }
        n++;
        return u;
    }

    SkipListNode* SkipLists::newNode(string x, int height){
        SkipListNode* toreturn = new SkipListNode(x, height);
        return toreturn;

    }

    void SkipLists::deleteNode(SkipListNode* todelete){
        delete todelete;
    }

}