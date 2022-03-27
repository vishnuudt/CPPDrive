#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

using namespace std;

namespace Drive::strings{

    class StringSearch{
        public:
            bool search(string one, string two);

    };


    class KnuthMorrisPratt{
        public:
            // KnuthMorrisPratt();
            bool search(string one, string pattern);

        private:
            char* radix;       // the radix
            int patLen;       // length of pattern
            // int** dfa;       // the KMP automoton
            unordered_map<char, int*> dfa; 

            void setup(string pattern);
            void tearDown();
            void print(unordered_map<char, int*> dfa);


    };
}