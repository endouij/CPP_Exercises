#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"
#include "Node.hpp"
#include <vector>
#include <sstream>



class ArrayNode : public Node
{
    private :
     std::vector<NodePtr> _value;

    public :
    ArrayNode()
    {

    }

    NodeKind kind(){
        return NodeKind::ARRAY;
    }

    std::string virtual print() const {
        std::string truc = "[";
        std::string separator ="";
        for(unsigned i = 0; i<_value.size();i++){
            truc += separator;
            truc += _value.at(i)-> print();
            separator = ",";
        }
        return truc + "]";
    }

    std::vector<NodePtr>& data(){
        return _value;
    }

    static std::unique_ptr<ArrayNode> make_ptr(){
        return std::make_unique<ArrayNode>(); 
    }

    int child_count(){
        return _value.size();
    }

    void push_back(NodePtr node){
        _value.push_back(std::move(node));
    }

    int height(){
        int result = 1;
        for(unsigned i = 0; i<_value.size();i++){
            int truc =  std::max(_value.at(i)->height(),0);
           if(truc > result){
            result = truc;
           }
        }
        return result +1;
    }

    int node_count(){
        int result = 1;
        for(unsigned i = 0; i<_value.size();i++){
            int truc =  _value.at(i)->node_count();
            result+=truc;
        }
        return result;
    }

};