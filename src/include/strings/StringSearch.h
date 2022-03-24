#pragma once

#include <string>
#include <memory>

using namespace std;

namespace Drive::strings{

    class StringSearch{
        public:
            bool search(string one, string two);

    };


    class KnuthMorrisPratt{
        public:
            KnuthMorrisPratt(string pattern);
            bool search(string one);

        private:
            int radix;       // the radix
            int stringLength;       // length of pattern
            int** dfa;       // the KMP automoton


    };
}