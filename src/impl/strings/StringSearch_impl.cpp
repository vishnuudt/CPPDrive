#include "strings/StringSearch.h"

namespace Drive::strings{

    bool StringSearch::search(string one, string two){
        int i = 0;
        int j = 0;
        int M = two.length();
        int N = one.length();

        for (; i < M; i++){
            j = 0;
            for (; j < N; j++){
                char c = two[i+j];
                char d = one[j];
                if (c != d){
                    break;
                }    
            }
            if (j == N){
                return true;
            }
        }

        return false;
    }

    bool KnuthMorrisPratt::search(string one, string two){
        return true;
    }

}