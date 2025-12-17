#include<iostream>
#include "node_deliver.hpp"
using namespace std;

bool add_node(string node){
    Database db;
    vector<string> nodes = nodeSerializer(node);
    for(auto & it: nodes){
        string res = db.addNode(node);
    }
}
bool remove_node(string node){
    Database db;
    vector<string> nodes = nodeSerializer(node);
    vector<string> deleted_nodes;
    int f = 0;
    for(auto & it: nodes){
        string res = db.deleteNode(node);
        if(res == "Node deleted successfully"){
            deleted_nodes.push_back(it);
        }else{
            f = 1; break;
        }
    }
    if(f){
        for(auto & it: deleted_nodes){
            string res = db.addNode(it);
        }
        return false;
    }
    return true;
}