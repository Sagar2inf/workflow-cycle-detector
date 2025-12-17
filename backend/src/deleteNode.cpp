#include "../include/database.hpp"

using namespace std;

string Database::deleteNode(const string& node){
    if(Nodes.find(node) == Nodes.end()){
        return "Node not found";
    }
    Nodes.erase(node);
    return "Node deleted successfully";
}