#include "orphan_node.hpp"

vector<string> orphan_nodes(Database& db){
    set<string> nodes = db.Nodes;
    map<string, set<pair<string, int>>> edges = db.Edges;
    set<string> connected_nodes;
    for(auto & it: edges){
        connected_nodes.insert(it.first);
        for(auto & jt: it.second){
            connected_nodes.insert(jt.first);
        }
    }
    vector<string> res;
    for(auto & node: nodes){
        if(connected_nodes.find(node) == connected_nodes.end()){
            res.push_back(node);
        }
    }
    return res;
}