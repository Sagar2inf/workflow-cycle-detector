#include "edge_deliver.hpp"

string add_edge(string edge_data){
    string chk = "";
    for(auto & it: edge_data){
        if(it == ' '){
            continue;
        }
        chk += it;
    }
    pair<vector<pair<string, string>>, vector<int>> edges = edgeSerializer(edge_data);    
    vector<pair<string, string>> edge_list = edges.first;
    vector<int> weights = edges.second;
    Database db;
    string chk_data = "";
    if(!weights.size()){
        for(auto & it: edge_list){
            chk_data += it.first + "->" + it.second + ",";
        }
    }else{
        for(int i = 0; i < edge_list.size(); i++){
            chk_data += edge_list[i].first + "-{" + to_string(weights[i]) + "}->" + edge_list[i].second + ",";
        }
    }
    if(chk_data != chk){
        return "Edge data malformed";
    }
    for(int i = 0; i < edge_list.size(); i++){
        string from = edge_list[i].first;
        string to = edge_list[i].second;
        int weight = 0;
        if(weights.size()){
            weight = weights[i];
        }
        string res = db.addEdge(from, to, weight);
    }
    return "Edges added successfully";
}

string remove_edge(string edge_data){
    pair<vector<pair<string, string>>, vector<int>> edges = edgeSerializer(edge_data);    
    vector<pair<string, string>> edge_list = edges.first;
    Database db;
    set<pair<string, string>>& rel = db.Relationships;
    for(auto & it: edge_list){
        if(rel.find(it) == rel.end()){
            return "some Edge not found";
        }
    }
    for(int i = 0; i < edge_list.size(); i++){
        string from = edge_list[i].first;
        string to = edge_list[i].second;
        string res = db.deleteEdge(from, to);
    }
    
    return "Edges deleted successfully";
}