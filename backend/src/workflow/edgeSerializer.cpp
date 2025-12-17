#include "serializer.hpp"
#include "int_str.hpp"
#include<iostream>
#include<algorithm>

using namespace std;

/*
1) unweighted directed graph:
    {"A" -> "B", "B" -> "C", "C" -> "D"}
2) weighted edges:
    {"A" -{"w"}->"B", "B" -{"w"}->"C", "C" -{"w"}->"D"}
*/



pair<vector<pair<string, string>>, vector<int>> edgeSerializer(string& data){
    while(true){
        char c = data[0];
        data.erase(data.begin());
        if(c == ':') break;
    }
    vector<pair<string, string>> edges;
    string s = "";
    for(auto & it: data){
        if(it == ' ' || it == '"') continue;
        s += it;
    }
    s.erase(s.begin()); s.pop_back();
    bool isweighted = 0;
    if(s.find("{") != string::npos) isweighted = 1;
    if(s.find("}") != string::npos) isweighted = 1;
    vector<int> weight;
    if(isweighted){
        string tmp = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == '{'){
                string w = "";
                i += 1;
                while(s[i] != '}' && i < s.size()){
                    w += s[i];
                    i++;
                }
                int wt = str_to_int(w);
                weight.push_back(wt);
                i += 1;
            }else{
                tmp += s[i];
                i += 1;
            }
        }
        s = tmp;
    }
    
    vector<pair<string, string>> edges;
    string tmp = "";
    int i = 0;
    while(i < s.size()){
        string u = "", v = "";
        if(i < s.size() - 1 && s[i] == '-' && s[i + 1] == '>'){
            u = tmp;
            i += 2;
            while(s[i] != ',' && i < s.size()){
                v += s[i];
                i++;
            }
            edges.push_back({u, v});
            i += 1;
        }else{
            tmp += s[i];
            i += 1;
        }
    }
    if(tmp.size()) edges.push_back({tmp, ""});
    pair<vector<pair<string, string>>, vector<int>> res;
    res.first = edges;
    res.second = weight;
    return res;
}