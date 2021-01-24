#include <iostream>
#include <map>
using namespace std;

int main(){
    map <string, int> mp;
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        string tmp; cin >> tmp;
        if(mp.count(tmp) == 0) mp[tmp] = 1; 
        else ++mp[tmp];
    }
    cin >> n;
    for(int i=0; i<n; ++i){
        string tmp; cin >> tmp;
        if(mp.count(tmp) == 0) mp[tmp] = -1; 
        else --mp[tmp];
    }
    int max = 0;
    for(auto x : mp){
        if(max < x.second)max = x.second;
    }
    cout << max << endl;
}