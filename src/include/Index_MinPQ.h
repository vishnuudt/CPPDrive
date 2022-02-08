#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <array>

using namespace std;

namespace Drive::IndexedMinPQ{

class IndexedMinPQ{
public:
    IndexedMinPQ() = delete;

    IndexedMinPQ(int max);

    virtual ~IndexedMinPQ();

    IndexedMinPQ(const IndexedMinPQ& );

    IndexedMinPQ(const IndexedMinPQ&& );

    IndexedMinPQ& operator=(const IndexedMinPQ& );

    IndexedMinPQ& operator=(const IndexedMinPQ&& );

    bool isEmpty();

    bool contains(int i);

    int size();

    void insert(int i, string key);

    int delMin();

    void decreaseKey(int i, string key);

    void increaseKey(int i, string key);

    static void exportItem();
    

private:
    std::string name{};
    int n{};
    int maxN{};
    std::array<int, 11> priority_queue{};
    std::array<int, 11> inverse_queue{};
    std::array<string, 11> keys{};


   bool greater(int i, int j);
   void exch(int i, int j);
   void swim(int k);
   void sink(int k);

};

}


