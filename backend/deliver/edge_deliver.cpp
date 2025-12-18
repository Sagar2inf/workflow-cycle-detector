#include "edge_deliver.hpp"
#include<iostream>

string add_edge(string edge_data){
    pair<vector<pair<string, string>>, vector<int>> edges = edgeSerializer(edge_data);    
    vector<pair<string, string>> edge_list = edges.first;
    vector<int> weights = edges.second;
    for(auto & it: edge_list){
        cout << it.first << "->" << it.second << ", ";
    }
    cout << endl;
    for(auto & it: weights){
        cout << it << " ";
    }
    cout << endl;
    int n = edge_list.size();
    for(int i = 0; i < n; i++){
        string from = edge_list[i].first;
        string to = edge_list[i].second;
        int weight = weights[i];
        string res = DB.addEdge(from, to, weight);
    }
    return "Edges added successfully";
}

string remove_edge(string edge_data){
    pair<vector<pair<string, string>>, vector<int>> edges = edgeSerializer(edge_data);    
    vector<pair<string, string>> edge_list = edges.first;
    set<pair<string, string>>& rel = DB.Relationships;
    for(auto & it: edge_list){
        if(rel.find(it) == rel.end()){
            return "some edge not found";
        }
    }
    int n = edge_list.size();
    for(int i = 0; i < n; i++){
        string from = edge_list[i].first;
        string to = edge_list[i].second;
        string res = DB.deleteEdge(from, to);
    }
    
    return "Edges deleted successfully";
}