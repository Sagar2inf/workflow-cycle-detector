#include<iostream>
#include "node_deliver.hpp"
using namespace std;

bool add_node(string node){
    vector<string> nodes = nodeSerializer(node);
    for(auto & it: nodes){
        string res = DB.addNode(it);
    }
    cout << DB.Nodes.size() << endl;
    for(auto & it: DB.Nodes){
        cout << it << " ";
    }
    cout << endl;

    return true;
}
bool remove_node(string node){
    vector<string> nodes = nodeSerializer(node);
    vector<string> deleted_nodes;
    int f = 0;
    for(auto & it: nodes){
        string res = DB.deleteNode(it);
        if(res == "Node deleted successfully"){
            deleted_nodes.push_back(it);
        }else{
            f = 1; break;
        }
    }
    if(f){
        for(auto & it: deleted_nodes){
            string res = DB.addNode(it);
        }
        return false;
    }
    // print current status
    cout << DB.Nodes.size() << endl;
    if(DB.Nodes.size()){
        for(auto & it: DB.Nodes){
            cout << it << " ";
        }
        cout << endl;
    }
    

    return true;
}