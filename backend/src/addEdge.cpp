#include "database.hpp"

using namespace std;

string Database::addEdge(const string& from, const string& to, int weight){
    if(Edges.find(from) != Edges.end()){
        set<pair<string, int>>& nodes = Edges[from];  
        vector<pair<string, int>> node_present;
        for(auto & it: nodes){
            if(it.first == to){
                node_present.push_back(it);
            }
        }
        for(auto & it: node_present){
            nodes.erase(it);
        }
    }
    Edges[from].insert({to, weight});
    Relationships.insert({from, to});
    Nodes.insert(from); Nodes.insert(to);
    return "Edge added successfully";
}
