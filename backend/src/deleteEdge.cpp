#include "database.hpp"

using namespace std;

string Database::deleteEdge(string& from, string& to){
    if(Edges.find(from) != Edges.end()){
        auto& nodes = Edges[from];
        pair<string, int> target;
        bool f = 0;
        for(auto & it: nodes){
            if(it.first == to){
                target = it;
                f = 1;
                break;
            }
        }
        if(!f){
            return "No edge found";
        }
        if(Relationships.find({from, to}) != Relationships.end()){
            Relationships.erase({from, to});
        }
        nodes.erase(target);
        Edges[from] = nodes;
        return "Edge deleted successfully";
    }else{
        return "No edge found";
    }
}