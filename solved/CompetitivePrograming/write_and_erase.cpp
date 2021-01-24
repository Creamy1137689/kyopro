#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int, int> mp;
    int n; cin >> n;
    for(int i = 0; i<n; ++i){
        int tmp; cin >> tmp;
        if(mp.count(tmp) == 0)mp[tmp] = 1;
        else mp.erase(tmp);
    };
    cout << mp.size() << endl;
}