#include "detect_cycle.hpp"

vector<int> vis;
bool dfs(vector<vector<int>>& adj, int s){
    vis[s] = 1;
    for(auto & it: adj[s]){
        if(vis[it] == 0){
            if(dfs(adj, it)) return true;
        }else if(vis[it] == 1){
            return true;
        }
    }
    vis[s] = 2;
    return false;
}
bool detect_cycle(Database& db){
    map<string, set<pair<string, int>>> graph = db.Edges;
    set<string> nodes = db.Nodes;
    map<string, int> ids;
    int k = 1;
    for(auto & it: nodes){
        ids[it] = k++;
    }
    int n = nodes.size();
    vector<vector<int>> adj(n + 1);
    for(auto & it: graph){
        int u = ids[it.first];
        for(auto & edge: it.second){
            int v = ids[edge.first];
            adj[u].push_back(v);
        }
    }
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            if(dfs(adj, i)) return true;
        }
    }
    return false;
}