#pragma once

#include <memory>
#include <chrono>
#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::chrono;

namespace Drive::CPP17{

using PairStrStr = std::pair<std::string, std::string>;

// Both the arms of if statement are not evaluated, only the one that matches or unmatches during compilation is
// used by the compiler.
template<typename T>
auto length_at_compile_time(T const& value){
    if constexpr(std::is_integral<T>::value){
        return value;
    }else {
        return value.length();
    }
}


class CPP17Features{
public:

    CPP17Features(int size);

    virtual ~CPP17Features();

    CPP17Features(const CPP17Features& );

    CPP17Features(CPP17Features&& );

    CPP17Features& operator=(const CPP17Features& );

    CPP17Features& operator=(CPP17Features&& );

    virtual void exportItem();

    void print(string&& message);


private:
		seconds secs{10};
		milliseconds millisecs{200};
        int*   m_data;
        int m_size;

};
}




