#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<long long>a={10,20,30,40,50};
    ofstream bin("out.bin",ios::binary);
    for(long long x:a) bin.write((char*)&x,sizeof(x));
    bin.close();
    ifstream b("out.bin",ios::binary);
    vector<long long>r;
    long long x;
    while(b.read((char*)&x,sizeof(x))) r.push_back(x);
    cout<<"ASCII input: ";
    for(long long y:a) cout<<y<<" ";
    cout<<"\nRecovered from binary: ";
    for(long long y:r) cout<<y<<" ";
}
