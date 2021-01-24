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
typedef long long ll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n,k,s; cin>>n>>k>>s;
    vector <int> a(n);
    if(s==(int)1e9)rep(i,n)a[i] = 1;
    else rep(i,n)a[i] = 1e9;

    rep(i,k)a[i] = s;

    for(auto x:a)cout<<x<<' '; cout<<endl; return 0;
}
