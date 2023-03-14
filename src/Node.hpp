#pragma once

#include <memory>
#include <string>
#include "InstanceCounter.hpp"

class Node : public InstanceCounter
{
    public :
    virtual std::string print() const = 0;
    virtual ~ Node() {};
    virtual int height() const = 0;
    virtual int node_count() const = 0;
};

using NodePtr = std::unique_ptr<Node>;
