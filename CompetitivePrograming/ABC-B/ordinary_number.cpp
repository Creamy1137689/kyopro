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
    int n; cin>>n;
    vector<int> p(n); rep(i,n)cin>>p[i];
    int ans = 0;
    REP(i,n-1)if((p[i-1]<p[i]&&p[i]<p[i+1])||(p[i-1]>p[i]&&p[i]>p[i+1]))ans++;
    cout<<ans<<endl; return 0;
}
