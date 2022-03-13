#include "trees/Node.h"


namespace Drive::CPP17::Trees{

 

Node::Node(string k, int v, bool c, int s): 
    key(k), value(v), color(c), size(s){
    std::cout << "cons Node" << std::endl;
}

Node::~Node(){
    std::cout << "des Node" << std::endl;
}

Node::Node(const Node& ){
    std::cout << "copy cons lval Node" << std::endl;
}

Node::Node(const Node&& ){
    std::cout << "copy cons rval Node" << std::endl;
}

Node& Node::operator=(const Node& ){
     std::cout << "assign lval Node" << std::endl;
     return *this;
}

Node& Node::operator=(const Node&& ){
    std::cout << " assign rval Node" << std::endl;
    return *this;
}

}