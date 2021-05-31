#include <iostream>
#include <string.h>

using namespace std;


class LSM{
public:

    LSM(){
        std::cout << "cons" << std::endl;
        name = "varshini";
    }

    ~LSM(){
        std::cout << "des" << std::endl;
    }

    int print();

private:
    std::string name{};

};