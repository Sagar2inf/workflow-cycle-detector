#include "database.hpp"

using namespace std;

set<string> Database::getChilds(const string& node){
    set<string> children;
    for(auto & it: Relationships){
        if(it.first == node) children.insert(it.second);
    }
    return children;
}