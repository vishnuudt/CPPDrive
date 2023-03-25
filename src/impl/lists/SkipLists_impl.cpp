#include "lists/SkipLists.h"

namespace Drive::CPP17::Lists{

    SkipLists::SkipLists(){
        std::cout << "cons SkipLists" << std::endl;
    }

    SkipLists::~SkipLists(){
        std::cout << "des SkipLists" << std::endl;
    }

    SkipLists::SkipLists(const SkipLists& ){
        std::cout << "copy cons lval SkipLists" << std::endl;
    }

    SkipLists::SkipLists(const SkipLists&& ){
        std::cout << "copy cons rval SkipLists" << std::endl;
    }

    SkipLists& SkipLists::operator=(const SkipLists& ){
        std::cout << "assign lval SkipLists" << std::endl;
        return *this;
    }

    SkipLists& SkipLists::operator=(const SkipLists&& ){
        std::cout << " assign rval SkipLists" << std::endl;
        return *this;
    }

    void SkipLists::exportItem(){
        SkipLists skips;
    }

}