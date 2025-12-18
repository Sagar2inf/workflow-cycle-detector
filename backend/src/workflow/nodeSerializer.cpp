#include<iostream>
#include<algorithm>
#include "workflow/serializer.hpp"

using namespace std;

vector<string> nodeSerializer(string& data){
    vector<string> nodes;
    while(true){
        char c = data[0];
        data.erase(data.begin());
        if(c == ':') break;
    }
    string s = "";
    for(auto & it: data){
        if(it == ' ') continue;
        if(it == '{' || it == '}') continue;
        if(it == '"') continue;
        s += it;
    }
    string tmp = "";
    for(int i = 0; i < int(s.size()); i++){
        if(s[i] == ','){
            nodes.push_back(tmp);
            tmp = "";
        }else{
            tmp += s[i];
        }
    }
    if(tmp.size()) nodes.push_back(tmp);
    return nodes;
}