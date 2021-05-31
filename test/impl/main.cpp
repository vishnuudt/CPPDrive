#include <iostream>
#include <string.h>
#include "LSM.h"

using namespace std;

/*
class MyName{
public:
    
    MyName(){
        std::cout << "cons" << std::endl;
        name = "varshini";
    }

    ~MyName(){
        std::cout << "des" << std::endl;
    }

    MyName(const MyName& ){
        std::cout << "copy cons lVal" << std::endl;
    }

    MyName(const MyName&& ){
        std::cout << "copy cons RVal" << std::endl;
    }

    MyName& operator=(const MyName& ){
        std::cout << "assign op lval" << std::endl;
        return *this;
    }

    MyName& operator=(const MyName&& ){
        std::cout << "assign op rval" << std::endl;
        return *this;
    }

    int print(){
        std::cout << "Hello kuttu " << name << std::endl;
        return 1;
    }

private:
    std::string name{};
};

*/

int main(int args, char** argv){
    {
        LSM my;
        my.print();
    }
}