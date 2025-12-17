#include "validator.hpp"

using namespace std;

string valid_add_edge(pair<vector<pair<string, string>>, vector<int>> & edges_wgt){
    vector<pair<string, string>> edges = edges_wgt.first;
    vector<int> weights = edges_wgt.second;
    if(edges.size() != weights.size()){
        return "Error: Mismatch in edges and weights count";
    } 
    return "Valid";
}