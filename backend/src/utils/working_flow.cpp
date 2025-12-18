#include "utils/working_flow.hpp"
#include<queue>

string min_flow(){
    map<string, set<pair<string, int>>> edges = DB.Edges;
    map<string, int> ids;
    int k = 1;
    for(auto & it: DB.Nodes){
        ids[it] = k++;
    }
    int n = DB.Nodes.size();
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> odegree(n + 1, 0);
    for(auto & it: edges){
        int u = ids[it.first];
        for(auto & jt: it.second){
            odegree[u] += 1;
            int v = ids[jt.first];
            int w = jt.second;
            adj[v].push_back({u, w});
        }
    }
    queue<int> q;
    for(int i= 1; i <= n; i++){
        if(odegree[i] == 0) q.push(i);
    }
    vector<int> cost(n + 1, 0);
    vector<int> node_flow;
    while(q.size()){
        int u = q.front(); q.pop();
        node_flow.push_back(u);
        for(auto to: adj[u]){
            int v = to.first, w = to.second;
            cost[v] = max(cost[v], cost[u] + w);
            odegree[v] -= 1;
            if(odegree[v] == 0) q.push(v);
        }
    }
    if(node_flow.size() != n){
        return "Graph has a cycle, min flow not possible";
    }
    string res_node = "Order of Nodes: ";
    string res_cost = "Time before each node: ";
    for(int i = 0; i < n; i++){
        int x = node_flow[i];
        int w = cost[x];
        string node_name = "";
        for(auto & it: ids){
            if(it.second == x){
                node_name = it.first;
                break;
            }
        }
        res_node += node_name + " ";
        res_cost += to_string(w) + " ";
    }
    return res_node + "\n" + res_cost;
}
