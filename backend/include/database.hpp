#include <string>
#include <optional>
#include <vector>
#include<set>
#include<map>

using namespace std;

class Database {
public: 
    set<string> Nodes;
    map<string, set<pair<string, int>>> Edges;
    set<pair<string, string>> Relationships;

    string addNode(const string& node);
    string addEdge(const string& from, const string& to, int weight);
    string deleteNode(const string& node);
    string deleteEdge(const string& from, string& to);
    set<string> getChilds(const string& node);
    set<string> getParents(const string& node);
};
