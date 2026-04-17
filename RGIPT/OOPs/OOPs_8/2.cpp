#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a={12,7,9,13,18,25,4};
    vector<int>d3,oth;
    for(int x:a){
        if(x%3==0) d3.push_back(x);
        else oth.push_back(x);
    }
    cout<<"Divisible by 3: ";
    for(int x:d3) cout<<x<<" ";
    cout<<"\nOthers: ";
    for(int x:oth) cout<<x<<" ";
}
