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



    void KnuthMorrisPratt::setup(string pattern){
        this->radix = new char[]{'1','2', '3', '4', '5', '\0'};
        this->patLen = pattern.length();

        char* head = this->radix;
        while (*head != '\0'){
            dfa[*head] = new int[patLen];
            head++;
        }

        char& p0 = pattern[0];
        dfa[p0][0] = 1; 
        for (int x = 0, j = 1; j < patLen; j++) {

            char* head = this->radix;
            while (*head != '\0'){
                char& c = *head;
                dfa[c][j] = dfa[c][x]; // Copy mismatch cases.
                head++;
            }
            print(dfa); //print
            char& p = pattern[j];
            dfa[p][j] = j+1;   // Set match case. 
            x = dfa[p][x];     // Update restart state. 
            print(dfa);
            
        } 
        
    }



    bool KnuthMorrisPratt::search(string text, string pattern){

        setup(pattern);

        // simulate operation of DFA on text
        int n = text.length();
        int i, j;
        for (i = 0, j = 0; i < n && j < patLen; i++) {
            char & c = text[i];
            j = dfa[c][j];
        }

        tearDown();

        if (j == patLen) {
            int res = i - patLen;
            cout << "text:" << text << "pattern:" << pattern << "result:" << res << endl;
            return res;    // found
        }
        return n;   
    }

    void KnuthMorrisPratt::tearDown(){
        /*for(int i = 0; i < radix ; ++i){
            delete [] dfa[i];
        }
        delete [] dfa;
        radix = 0 ;
        patLen = 0;*/

        for (auto iter = dfa.cbegin(); iter != dfa.cend(); ++iter){
            int* p = iter->second;
            delete p;
        }
        delete [] radix;
        dfa.clear();
    }

    void KnuthMorrisPratt::print(unordered_map<char, int*> dfa){
        for (auto iter = dfa.cbegin(); iter != dfa.cend(); ++iter){
            cout << "key: " << iter->first << " value:";
            for (int j = 0; j < patLen; ++j){
                cout << iter->second[j];
                if (j < patLen -1){
                    cout << "," ;
                }
            }
            cout << endl;
        }

        cout << "--------------------" << endl;
        
    }

}