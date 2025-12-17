#include "disconnected_flow.hpp";
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> p, sz;
int find_set(int v){
    if(v == p[v]) return v;
    return p[v] = find_set(p[v]);
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}
bool checkflow_connectivity(Database& db){
    map<string, set<pair<string, int>>> adj = db.Edges;
    map<string, int> ind;
    int id = 1;
    for(auto & it: adj){
        if(ind.find(it.first) == ind.end()){
            ind[it.first] = id++;
        }
        for(auto & jt: it.second){
            if(ind.find(jt.first) == ind.end()){
                ind[jt.first] = id++;
            }
        }
    }    
    p.assign(id, 0);
    iota(p.begin(), p.end(), 0);
    sz.assign(id + 1, 1);
    for(auto & it: adj){
        int u = ind[it.first];
        for(auto & jt: it.second){
            int v = ind[jt.first];
            union_set(u, v);
        }
    }
    for(int i = 1; i < id; i++){
        find_set(i);
    }
    set<int> st;
    for(int i = 1; i < id; i++){
        st.insert(p[i]);
    }
    int number_of_components = st.size();
    return number_of_components;

}

