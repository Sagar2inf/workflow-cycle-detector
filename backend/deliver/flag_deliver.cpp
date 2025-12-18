#include "flag_deliver.hpp"

string all_flags(){
    if(DB.Nodes.size() == 0){
        return "Empty Graph?: Yes\nCycle Present?: No\nFlow Connected?: Yes\nNegative Cycle Present?: No\nNegative Weight Edges Present?: No\nOrphan Nodes Present?: No\n";
    }
    string graph = debug();
    bool is_cycle = detect_cycle();
    bool is_connected = checkflow_connectivity();
    vector<string> negative_cycle_nodes = detect_negative_cycle();
    vector<pair<string, string>> negative_weight_edges = negative_weighted_edge();
    vector<string> orphaned_nodes = orphan_nodes();
    string res = "EmptyGraph?: No\n";
    if(is_cycle){
        res += "Cycle Present?: Yes\n";
    }else{
        res += "Cycle Present?: No\n";
    }
    if(is_connected){
        res += "Flow Connected?: Yes\n";
    }else{
        res += "Flow Connected?: No\n";
    }
    if(negative_cycle_nodes.size() > 0){
        res += "Negative Cycle Present?: Yes\n";
        res += "Nodes in Negative Cycle: ";
        for(auto & it: negative_cycle_nodes){
            res += it + " ";
        }
        res += "\n";
    }else{
        res += "Negative Cycle Present?: No\n";
    }
    if(negative_weight_edges.size() > 0){
        res += "Negative Weight Edges Present?: Yes\n";
    }else{
        res += "Negative Weight Edges Present?: No\n";
    }
    if(orphaned_nodes.size() > 0){
        res += "Orphan Nodes Present?: Yes\n";
    }else{
        res += "Orphan Nodes Present?: No\n";
    }
    return graph + res;
}