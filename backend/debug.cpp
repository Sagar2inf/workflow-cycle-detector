#include "debug.hpp"

string debug(){
    string res = "All Nodes in Graph: \n";
    // cout << "All Nodes in graph" << endl;
    for(auto & it: DB.Nodes){
        // cout << it << " ";
        res += it + " ";
    }
    // cout << endl;
    res += "\n";
    // cout << "The current graph" << endl;
    res += "The current graph: \n";
    for(auto & it: DB.Edges){
        string from = it.first;
        for(auto & jt: it.second){
            string to = jt.first;
            int weight = jt.second;
            // cout << from << " --{" << weight << "}--> " << to << endl;
            res += from + " --{" + to_string(weight) + "}--> " + to + ", ";
        }
    }
    res += "\n";
    // cout << "All Relationships in graph" << endl;
    res += "All Relationships in graph: \n";
    for(auto & it: DB.Relationships){
        // cout << it.first << " -> " << it.second << endl;
        res += it.first + " -> " + it.second + ", ";
    }
    res += "\n";
    return res;
}