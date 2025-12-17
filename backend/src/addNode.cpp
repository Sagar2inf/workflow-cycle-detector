#include "../include/database.hpp"

using namespace std;

string Database::addNode(const string& node){
    if(Nodes.find(node) != Nodes.end()){
        return "Node is already present";
    }
    Nodes.insert(node);
    return "Node added successfully";
}

