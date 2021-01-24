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
#define REP(i,n) for(int i = 1; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    int n,x; cin>>n>>x;
    vector <int> l(n);rep(i,n)cin>>l[i];
    int point = 0; int ans = 0;
    for(int i = 0; i<n&&point <= x; ++i){
        ++ans;
        point += l[i];
    }
    if(point <=x)++ans;
    cout<<ans<<endl;return 0;
}