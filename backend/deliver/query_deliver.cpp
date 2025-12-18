#include "query_deliver.hpp"

string get_children(string node_str){
    vector<string> nodes = nodeSerializer(node_str);
    string node = nodes[0];
    set<string> children = DB.getChildren(node);
    string res = "";
    for(auto & it: children){
        res += it + " ";
    }
    return res;
}

string get_parents(string node_str){
    vector<string> nodes = nodeSerializer(node_str);
    set<string> parents = DB.getParents(nodes[0]);
    string res = "";
    for(auto & it: parents){
        res += it + " ";
    }
    return res;
}