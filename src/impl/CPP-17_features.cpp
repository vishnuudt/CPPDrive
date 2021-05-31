#include "CPP-17_features.h"

namespace Drive::CPP17{

    CPP17Features::CPP17Features(){
        std::cout << "cons" << std::endl;
    }

    CPP17Features::~CPP17Features(){
        std::cout << "des" << std::endl;
        _mapElement.erase(_mapElement.begin());
    }

    CPP17Features::CPP17Features(const CPP17Features& ){
        std::cout << "copy cons lVal" << std::endl;
    }

    CPP17Features::CPP17Features(const CPP17Features&& ){
        std::cout << "copy cons RVal" << std::endl;
    }

    CPP17Features& CPP17Features::operator=(const CPP17Features& ){
        std::cout << "assign op lval" << std::endl;
        return *this;
    }

    CPP17Features& CPP17Features::operator=(const CPP17Features&& ){
        std::cout << "assign op rval" << std::endl;
        return *this;
    }

    void CPP17Features::exportItem(){
        std::cout << secs.count() << std::endl;

        int n{64};
        string s{"Some"};
        std::cout << "length(n) " << length_at_compile_time(n) << std::endl;
        std::cout << "length(s) " << length_at_compile_time(s) << std::endl;

        // structured binding in action
        auto [iter, success] = _mapElement.insert ( PairStrStr("sedia"s, "chair"s) );
        std::cout << "insert " << " with " << success << std::endl;

        // for loop structured bindings
        for (const auto& [first, second] : _mapElement){
            std::cout << "f " << first << " s " << second << std::endl;
        }

        int x = 20;
        double y = 25.4;
        std::vector<std::string> names{"12", "345", "6789", "101112"};
        
        // captures by value, by reference
        std::sort(std::begin(names), std::end(names), [x , &y] (std::string const& a, std::string const& b){
            return a.length() > b.length();
        });
        std::cout << names[0] << std::endl;
        std::unique_ptr<int> ptr = std::make_unique<int>(20);

        // and by init captures
        auto const& lambda = [p = std::move(ptr)](){
            std::cout << "inside init captures" << *p << std::endl;
        };

        lambda();

        if (ptr){
            std::cout << "outside init captures" << *ptr << std::endl;
        }

        // if scoped variable declaration.. ALSO works on SWITCH
        if(const auto its = std::find(std::begin(names), std::end(names), "3"); its != std::end(names)){
            *its = "***";
        }

        std::for_each(std::cbegin(names), std::cend(names), [this](const std::string& a){
            std::cout << a << std::endl;
        });

			
    }


}