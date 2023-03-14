#pragma once
#include <memory>

#include "Node.hpp"


class Leaf : public Node
{
    public:
    int height(){
        return 0;
    }
    int node_count(){
        return 1;
    }

};