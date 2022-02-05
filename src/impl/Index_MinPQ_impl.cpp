#include "Index_MinPQ.h"

namespace Drive::IndexedMinPQ{

    IndexedMinPQ::IndexedMinPQ(int max):name{}, n{0}, maxN{max}, 
    priority_queue{0}, inverse_queue{0},
    keys{""}{}

    IndexedMinPQ::~IndexedMinPQ(){
        std::cout << "des minPQ" << std::endl;
    }

    IndexedMinPQ::IndexedMinPQ(const IndexedMinPQ& ){
        std::cout << "copy cons lVal minPQ" << std::endl;
    }

    IndexedMinPQ::IndexedMinPQ(const IndexedMinPQ&& ){
        std::cout << "copy cons RVal minPQ" << std::endl;
    }

    IndexedMinPQ& IndexedMinPQ::operator=(const IndexedMinPQ& ){
        std::cout << "assign op lval minPQ" << std::endl;
        return *this;
    }

    IndexedMinPQ& IndexedMinPQ::operator=(const IndexedMinPQ&& ){
        std::cout << "assign op rval minPQ" << std::endl;
        return *this;
    }

    bool IndexedMinPQ::isEmpty(){
        return true;
    }

    bool IndexedMinPQ::contains(int i){
        return true;
    }

    int IndexedMinPQ::size(){
        return 0;
    }

    void IndexedMinPQ::insert(int i, string key){
        if (i < 0 | i >= maxN) cerr << "index >= capacity: " << endl;
        // if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
        n++;
        inverse_queue[i] = n;
        priority_queue[n] = i;
        keys[i] = key;
        swim(n);
    }

    bool IndexedMinPQ::greater(int i, int j) {
        int ith = priority_queue[i];
        int jth = priority_queue[j];
        const string& ithString = keys[ith];
        const string& jthString = keys[jth];
        return ithString.compare(jthString) > 0;
    }

    void IndexedMinPQ::exch(int i, int j) {
        int swap = priority_queue[i];
        priority_queue[i] = priority_queue[j];
        priority_queue[j] = swap;
        inverse_queue[priority_queue[i]] = i;
        inverse_queue[priority_queue[j]] = j;
    }

    void IndexedMinPQ::swim(int k) {
        while (k > 1 && greater(k/2, k)) {
            exch(k, k/2);
            k = k/2;
        }
    }

    void IndexedMinPQ::sink(int k) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && greater(j, j+1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }


    int IndexedMinPQ::maxIndex(){
        return 1;
    }

    void IndexedMinPQ::exportItem(){
        std::array<string, 10> strings = { std::string("it"), 
        "was", "the", "best", "of", "times", "it", "was", "the", "worst" };

        {
            IndexedMinPQ pq(strings.size());

            for (int i = 0; i < strings.size(); i++) {
                pq.insert(i, strings[i]);
            }
        }

        // delete and print each key
        /* while (!pq.isEmpty()) {
            int i = pq.delMin();
            StdOut.println(i + " " + strings[i]);
        }
        

        // reinsert the same strings
        for (int i = 0; i < strings.length; i++) {
            pq.insert(i, strings[i]);
        }*/

        // print each key using the iterator
        /*for (int i : pq) {
            StdOut.println(i + " " + strings[i]);
        }
        while (!pq.isEmpty()) {
            pq.delMin();
        }*/


    }

    
}

