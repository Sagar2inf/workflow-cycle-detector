#include "negative_cycle.hpp"
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

vector<string> detect_negative_cycle(Database& db){
    map<string, set<pair<string, int>>> graph = db.Edges;
    map<string, int> ids;
    int k = 1;
    for (auto& node : db.Nodes) {
        ids[node] = k++;
    }
    int n = ids.size();
    vector<Edge> adj;
    for(auto & it: graph){
        int u = ids[it.first];
        for(auto & edge: it.second){
            int v = ids[edge.first];
            long long w = edge.second;
            Edge e = {u, v, w};
            adj.push_back(e);
        }
    }
    vector<int> d(n + 1, 0);
    vector<int> p(n + 1, -1);
    int x;
    for(int i = 1; i <= n; i++){
        x = -1;
        for(auto &e: adj){
            if(d[e.u] + e.w < d[e.v]){
                d[e.v] = d[e.u] + e.w;
                p[e.v] = e.u;
                x = e.v;
            }
        }
    }
    
    if(x == -1){
        return {};
    }
    for(int i = 1; i <= n; i++){
        x = p[x];
    }

    vector<int> cycle;
    int cur = x;
    do {
        cycle.push_back(cur);
        cur = p[cur];
    } while (cur != x);
    cycle.push_back(x);

    reverse(cycle.begin(), cycle.end());
    vector<string> res;
    for(auto & it: cycle){
        for(auto & pair: ids){
            if(pair.second == it){
                res.push_back(pair.first);
                break;
            }
        }
    }
    return res;
}