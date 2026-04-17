#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="Hello world this is test";
    stringstream ss(s);
    vector<string> v;
    string w;
    while(ss>>w) v.push_back(w);
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
        if(i) cout<<" ";
    }
}
