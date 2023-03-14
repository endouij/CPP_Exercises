#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"



class StringLeaf : public Leaf
{
    private :
    std::string _value;

    public :
    StringLeaf(std::string val)
        :_value {val}
    {

    }

    NodeKind kind(){
        return NodeKind::STRING;
    }

    std::string virtual print() const {
        return "\""+_value+"\"";
    }

    std::string data(){
        return _value;
    }

    static std::unique_ptr<StringLeaf> make_ptr(std::string strin){
        return std::make_unique<StringLeaf>(strin); 
    }

};