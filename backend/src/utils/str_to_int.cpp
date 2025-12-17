#include "int_str.hpp"

using namespace std;

int str_to_int(string& s){
    int res = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        res += (s[i] - '0') * pow(10, n - i - 1);
    }
    return res;
}

string int_to_str(int n){
    if(n == 0) return "0";
    string res = "";
    while(n > 0){
        res = char((n % 10) + '0') + res;
        n /= 10;
    }
    return res;
}