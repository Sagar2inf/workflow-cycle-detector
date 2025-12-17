#include "get_uncyclic_min_flow.hpp"

vector<int> p, sz;
int find(int v){
    if(v == p[v]) return v;
    return p[v] = find(p[v]);
}

void make(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
}
map<string, set<string>> get_flow(Database& db){
    set<string> nodes = db.Nodes;
    map<string, set<pair<string, int>>> edges = db.Edges;
    map<string, int> ids;
    int k = 1;
    int n = nodes.size();
    for(auto & it: nodes){
        ids[it] = k++;
    }
    vector<pair<int, pair<int, int>>> edge_list;
    for(auto & it: edges){
        int u = ids[it.first];
        for(auto & edge: it.second){
            int v = ids[edge.first];
            int w = edge.second;
            edge_list.push_back({w, {u, v}});
        }
    }
    p.assign(n + 1, 0);
    sz.assign(n + 1, 1);
    for(int i = 0; i <= n; i++){
        p[i] = i;
    }
    sort(edge_list.begin(), edge_list.end());
    vector<pair<string, string>> flow;
    vector<pair<int, int>> used_edges;
    for(auto & it: edge_list){
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(find(u) != find(v)){
            used_edges.push_back({it.second.first, it.second.second});
            make(u, v);
        }
    }
    for(auto & it: used_edges){
        string from, to;
        for(auto & pair: ids){
            if(pair.second == it.first){
                from = pair.first;
            }
            if(pair.second == it.second){
                to = pair.first;
            }
        }
        flow.push_back({from, to});
    }
    map<string, set<string>> res;
    for(auto & it: flow){
        res[it.first].insert(it.second);
    }
    return res;
}