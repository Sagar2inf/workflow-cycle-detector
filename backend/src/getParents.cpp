#include "database.hpp"

using namespace std;

set<string> Database::getParents(string& node){
    set<string> parents;
    for(auto & it: Relationships){
        if(it.second == node){
            parents.insert(it.first);
        }
    }
    return parents;
}