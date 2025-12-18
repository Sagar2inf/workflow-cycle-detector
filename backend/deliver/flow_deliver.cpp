#include "flow_deliver.hpp"

string min_flow(){
    map<string, set<pair<string, int>>> edges = DB.Edges;
    int is_negative = 0;
    for(auto & it: edges){
        for(auto & jt: it.second){
            if(jt.second < 0){
                is_negative = 1;
                break;
            }
        }
        if(is_negative) break;
    }
    if(is_negative){
        return "Graph has negative weight edge, min flow not possible";
    }
    if(!DB.Nodes.size()) return "Graph is empty!";
    min_flow();
}