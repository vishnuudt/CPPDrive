#pragma once

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace Drive::CPP17::Lists{


struct SkipListNode {
    string x;
    int height;     // length of next
    int *length;
    SkipListNode **next;

    SkipListNode(string input, int hei):x{input}, height{hei}{

    }

    ~SkipListNode(){
        delete length;
        delete [] next;
    }
};

class SkipLists{

    public:

        SkipLists();

        virtual ~SkipLists();

        SkipLists(const SkipLists& );

        SkipLists(const SkipLists&& );

        SkipLists& operator=(const SkipLists& );

        SkipLists& operator=(const SkipLists&& );

        static void exportItem();


        //functional interface
        string get(int i);
        string set(int i, string x);
        void add(int i, string x);
        string remove(int i);
        

    private:
           int h;
           int n;
           SkipListNode* sentinel;
           SkipListNode* findPred(int i);
           SkipListNode* newNode(string x, int height);
           SkipListNode* add(int i, SkipListNode *w);
           void deleteNode(SkipListNode*);
           int pickHeight();


};



}