#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;int array[n+1]; for(int i = 1; i<=n; ++i)cin >> array[i];
    map <int, int> mp;
    int index = 1, count_b_pushed = 0;
    for(;;){
        ++count_b_pushed;
        if(array[index] == 2){ cout << count_b_pushed << endl; return 0;}
        if(mp.count(array[index])){ cout << -1 << endl; return 0;}
        else{mp[array[index]] = 1; index = array[index];}
    }
}