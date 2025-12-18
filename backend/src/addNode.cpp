#include "../include/database.hpp"
#include<iostream>

using namespace std;

string Database::addNode(string& node){
    if(Nodes.find(node) != Nodes.end()){
        return "Node is already present";
    }
    Nodes.insert(node);
    return "Node added successfully";
}

