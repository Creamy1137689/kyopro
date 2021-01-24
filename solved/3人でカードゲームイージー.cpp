#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 537427207;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    vector<queue<char>> qs(3);
    string a,b,c;cin>>a>>b>>c;
    rep(i,a.size())qs[0].push(a[i]);
    rep(i,b.size())qs[1].push(b[i]);
    rep(i,c.size())qs[2].push(c[i]);
    int next = 0;
    rep(i,a.size()+b.size()+c.size()){
        if(qs[next].empty()){cout<<(char)(next+'A')<<endl; return 0;}
        int bf = next;
        next = qs[next].front()-'a';
        qs[bf].pop();
    }
}