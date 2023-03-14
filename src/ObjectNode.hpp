#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"
#include "Node.hpp"
#include <vector>
#include <sstream>
#include <map>



class ObjectNode : public Node
{
    private :
      std::map<std::string, NodePtr> _map;

    public :
    ObjectNode()
    {

    }

    NodeKind kind(){
        return NodeKind::OBJECT;
    }

    std::string virtual print() const {
        std::string truc = "{";
        std::string separator ="";
        for(auto i = _map.cbegin(); i!=_map.cend();++i){
            truc+= separator;
            truc +="\"";
            truc += i->first;
            truc +="\":";
            truc += i->second->print();
            /*if((++i) == _map.cend()){
                break;
            }
            --i;*/
            separator = ',';
        }
        return truc + "}";
    }

    std::map<std::string, NodePtr>& data(){
        return _map;
    }

    static std::unique_ptr<ObjectNode> make_ptr(){
        return std::make_unique<ObjectNode>(); 
    }

    int child_count(){
        return _map.size();
    }

    void insert(std::string string ,NodePtr node){
        _map.insert({string,std::move(node)});
    }

    int height(){
        int result = 1;
        for(auto i = _map.cbegin(); i!=_map.cend();++i){
           int truc =  std::max(i->second->height(),0);
           if(truc > result){
            result = truc;
           }
        }
        return result;
    }

    int node_count(){
        int result = 1;
        for(auto i = _map.cbegin(); i!=_map.cend();++i){
           int truc =  i->second->node_count();
           result+=truc;
        }
        return result;
    }

};