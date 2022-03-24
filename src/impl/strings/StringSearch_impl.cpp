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

    KnuthMorrisPratt::KnuthMorrisPratt(string pattern){
        this->radix = 256;
        this->stringLength = pattern.length();

        // build DFA from pattern
        dfa = new int*[radix]; 
        for (int i = 0; i < radix ; ++i){
            dfa[i] = new int[stringLength];
        }
        int p0 = pattern[0];
        dfa[p0][0] = 1; 
        for (int x = 0, j = 1; j < stringLength; j++) {
            for (int c = 0; c < radix; c++) {
                dfa[c][j] = dfa[c][x]; // Copy mismatch cases.
            }                     
            dfa[pattern[j]][j] = j+1;   // Set match case. 
            x = dfa[pattern[j]][x];     // Update restart state. 
        } 
    }

    bool KnuthMorrisPratt::search(string text){
        // simulate operation of DFA on text
        int n = text.length();
        int i, j;
        for (i = 0, j = 0; i < n && j < stringLength; i++) {
            j = dfa[text[i]][j];
        }
        if (j == stringLength) return i - stringLength;    // found
        return n;   
    }

}