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
    int n;cin>>n;
    vector <int> a(n); vector <int> b(n); vector<int> c(n-1);
    rep(i,n)cin>>a[i];rep(i,n)cin>>b[i];rep(i,n-1)cin>>c[i];
    int ans = 0; rep(i,n)ans+=b[i];
    rep(i,n-1)if(a[i] - a[i+1] == -1)ans+=c[a[i]-1];
    cout<<ans<<endl;return 0;
}
