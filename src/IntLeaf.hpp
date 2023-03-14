#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"



class IntLeaf : public Leaf
{
    private :
    int _value;

    public :
    IntLeaf(int val)
        :_value {val}
    {

    }

    NodeKind kind(){
        return NodeKind::INT;
    }

    std::string virtual print() const {
        return std::to_string(_value);
    }

    int data(){
        return _value;
    }

    static std::unique_ptr<IntLeaf> make_ptr(int in){
        return std::make_unique<IntLeaf>(in); 
    }





};