#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    map <char,int> set;
    char tmp;
    rep(i,4){
        cin >> tmp;
        if(set.count(tmp) == 0)set[tmp] = 1;
        else set[tmp]++;
    }
    if(set.size() == 2 && set[tmp] == 2)cout<<"Yes" << endl;
    else cout <<"No"<<endl; return 0;
}
