#include "CPP-17_features.h"

namespace Drive::CPP17{

    CPP17Features::CPP17Features(int size): m_size{size}{
        std::cout << "cons" << std::endl;
        this->m_data = new int[size];
    }

    CPP17Features::~CPP17Features(){
        std::cout << "des" << std::endl;
        delete [] m_data;
    }

    CPP17Features::CPP17Features(const CPP17Features& other){
        std::cout << "copy cons lVal" << std::endl;
        m_data = new int[other.m_size];  // (1)
        std::copy(other.m_data, other.m_data + other.m_size, m_data);  // (2)
        m_size = other.m_size;
    }

    CPP17Features::CPP17Features(CPP17Features&& other){
        std::cout << "copy cons RVal" << std::endl;
        m_data = other.m_data;   // (1)
        m_size = other.m_size;
        other.m_data = nullptr;  // (2)
        other.m_size = 0;
    }

    CPP17Features& CPP17Features::operator=(const CPP17Features& other){
        std::cout << "assign op lval" << std::endl;
        if(this == &other) return *this;  // (1)
        delete[] m_data;  // (2)

        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size;
        return *this;  // (3)
    }

    CPP17Features& CPP17Features::operator=(CPP17Features&& other){
        std::cout << "assign op rval" << std::endl;
        
        if (this == &other) return *this;

        delete[] m_data;         // (1)

        m_data = other.m_data;   // (2)
        m_size = other.m_size;

        other.m_data = nullptr;  // (3)
        other.m_size = 0;

        return *this;
    }

    void CPP17Features::exportItem(){
        std::cout << secs.count() << std::endl;
        std::unordered_map<std::string, std::string> _mapElement;

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