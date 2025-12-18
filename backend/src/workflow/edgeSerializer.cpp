#include "workflow/serializer.hpp"
#include<iostream>
#include<algorithm>

using namespace std;

/*
1) unweighted directed graph:
    {"edge":"A -> B, B -> C, C -> D"}
2) weighted edges:
    {"A" -{"w"}->"B", "B" -{"w"}->"C", "C" -{"w"}->"D"}
*/



pair<vector<pair<string, string>>, vector<int>> edgeSerializer(string data){
    while(true){
        int f = 0;
        if(data[0] == ':') f = 1;
        data.erase(data.begin());
        if(f) break;
    }
    data.erase(data.begin()); data.pop_back(); data.pop_back();
    vector<pair<string, string>> edges;
    string s = "";
    for(auto & it: data){
        if(it == ' ') continue;
        s += it;
    }
    bool isweighted = 0;
    if(s.find("{") != string::npos) isweighted = 1;
    if(s.find("}") != string::npos) isweighted = 1;
    vector<int> weight;
    string ss = "";
    if(isweighted){
        string tmp = "";
        int f = 0;
        for(int i = 0; i < int(s.size()); i++){
            if(s[i] == '{') f = 1;
            else if(s[i] == '}'){
                int wt = str_to_int(tmp);
                weight.push_back(wt);
                tmp = "";
                f = 0;
                continue;
            }else if(f){
                tmp += s[i];
            }
            if(!f) ss += s[i];
        }
    }else{
        ss = s;
    }
    string tmp = "";
    int i = 0;
    while(i < ss.size()){
        tmp += ss[i];
        if(ss[i] == '>'){
            if(isweighted){
                tmp.pop_back(); tmp.pop_back(); tmp.pop_back();
            }else{
                tmp.pop_back(); tmp.pop_back();
            }
            string u = tmp; tmp = "";
            int j = i + 1;
            while(j < ss.size() && ss[j] != ','){
                tmp += ss[j]; j += 1;
            }
            string v = tmp;
            edges.push_back({u, v});
            tmp = "";
            i = j + 1;
        }else{
            i += 1;
        }
    }
    if(!isweighted) weight.assign(edges.size(), 0);
    pair<vector<pair<string, string>>, vector<int>> res;
    res.first = edges;
    res.second = weight;
    return res;
}