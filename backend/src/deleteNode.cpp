#include "../include/database.hpp"
#include<iostream>
using namespace std;

string Database::deleteNode(string& node){
    if(Nodes.find(node) == Nodes.end()){
        return "Node not found";
    }
    Nodes.erase(node);
    if(Edges.find(node) != Edges.end()){
        Edges.erase(node);
    }
    for(auto & it: Edges){
        auto& neighbors = it.second;
        vector<pair<string, int>> to_delete;
        for(auto & jt: neighbors){
            if(jt.first == node){
                to_delete.push_back(jt);
            }
        }
        for(auto & jt: to_delete){
            neighbors.erase(jt);
            Relationships.erase({it.first, jt.first});
        }
        Edges[it.first] = neighbors;
    }
    vector<pair<string, string>> to_delete;
    for(auto & it: Relationships){
        if(it.first == node || it.second == node){
            to_delete.push_back(it);
        }
    }
    for(auto & it: to_delete){
        Relationships.erase(it);
    }
    return "Node deleted successfully";
}