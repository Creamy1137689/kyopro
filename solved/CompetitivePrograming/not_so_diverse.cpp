#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    map <int, int> mp;
    for(int i=0; i<n; ++i){
        int tmp; cin >> tmp;
        if(mp.count(tmp) == 0) mp[tmp] = 1;
        else ++mp[tmp];
    }
    int min[mp.size()];
    int i = 0;
    for(auto x : mp){
        min[i++] = x.second;
    }
    sort(min,min+mp.size());
    int result = 0;
    for(int i = 0; i<(int)(mp.size()-k); i++) result += min[i];
    cout << result << endl; return 0;
}