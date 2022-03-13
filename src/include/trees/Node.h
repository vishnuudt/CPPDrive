#pragma once

#include <iostream>
#include <memory>

using namespace std;

namespace Drive::CPP17::Trees{

    class Node;
    using NodeUniqPtr = std::unique_ptr<Node>;

    class Node{
    public:
        inline const static bool RED = true;
        inline const static bool BLACK = false;  

        Node() = delete;

        Node(string key, int value, bool color, int size);

        virtual ~Node();

        Node(const Node& );

        Node(const Node&& );

        Node& operator=(const Node& );

        Node& operator=(const Node&& );

    // private:
        std::string key{};
        int value{};
        NodeUniqPtr left;
        NodeUniqPtr right;
        bool color;
        int size;

    };

}