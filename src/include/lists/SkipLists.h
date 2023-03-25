#pragma once

#include <iostream>
#include <memory>

using namespace std;

namespace Drive::CPP17::Lists{


class SkipLists{

    public:

        SkipLists();

        virtual ~SkipLists();

        SkipLists(const SkipLists& );

        SkipLists(const SkipLists&& );

        SkipLists& operator=(const SkipLists& );

        SkipLists& operator=(const SkipLists&& );

        static void exportItem();

    private:



};

}