#include "Index_MinPQ.h"

namespace Drive::IndexedMinPQ{

    IndexedMinPQ::IndexedMinPQ(int max):name{}, priority_queue{max, 0}, inverse_queue{max, 0}{}

    IndexedMinPQ::~IndexedMinPQ(){
        std::cout << "des minPQ" << std::endl;
        priority_queue.erase(priority_queue.begin());
        inverse_queue.erase(inverse_queue.begin());
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

    void IndexedMinPQ::insert(int i){

    }

    int IndexedMinPQ::maxIndex(){
        return 1;
    }

    void IndexedMinPQ::exportItem(){
        vector<string> strings{ "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst" };

        IndexedMinPQ pq(strings.size());

        for (int i = 0; i < strings.size(); i++) {
            // pq.insert(i, strings[i]);
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

