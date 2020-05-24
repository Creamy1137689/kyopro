#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c; cin >> a >> b >> c;
    map <int, int> mp;
    for(int i = 0; ; ++i){
        int tmp = a*i%b;
        if(mp.count(tmp))break;
        else mp[tmp] = 1;
    }
    cout << (mp.count(c) ? "YES" : "NO") << endl; return 0;
}