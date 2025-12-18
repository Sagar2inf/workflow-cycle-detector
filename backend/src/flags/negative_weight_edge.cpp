#include "flags/negative_weight_edge.hpp"

vector<pair<string, string>> negative_weighted_edge(){
    map<string, set<pair<string, int>>> graph = DB.Edges;
    vector<pair<string, string>> res;
    for(auto & it: graph){
        string u = it.first;
        for(auto & edge: it.second){
            string v = edge.first;
            int w = edge.second;
            if(w < 0){
                res.push_back({u, v});
            }
        }
    }
    return res;
}