#include<iostream>
#include<algorithm>
#include "serializer.hpp"

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
        s += it;
    }
    string tmp = "";
    while(s.size()){
        if(s.back() == ','){
            tmp.pop_back();
            tmp.erase(tmp.begin());
            reverse(tmp.begin(), tmp.end());
            nodes.push_back(tmp);
            tmp = "";
            s.pop_back();
            continue;
        }
        tmp += s.back();
        s.pop_back();
    }
    if(tmp.size()){
        tmp.erase(tmp.begin());
        tmp.pop_back();
        reverse(tmp.begin(), tmp.end());
        nodes.push_back(tmp);
    }

    return nodes;
}