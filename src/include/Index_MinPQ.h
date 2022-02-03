#pragma once

#include <iostream>
#include <string.h>
#include <vector>

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

    void insert(int i);

    int maxIndex();

    static void exportItem();
    

private:
    std::string name{};
    std::vector<int> priority_queue{};
    std::vector<int> inverse_queue{};

};

}


