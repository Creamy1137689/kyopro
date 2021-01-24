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
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

struct edge{int from,to,c;};

int main(){
    int MAX_V = 2510, MAX_E = 5020;
    int V,E,P; cin>>V>>E>>P;
    vector<edge> ed(MAX_E);
    vector<ll> p(MAX_V,INF);
    rep(i,E){cin>>ed[i].from>>ed[i].to>>ed[i].c; ed[i].c *= -1;}

    p[1] = 0;
    rep(i,V){
        rep(j,E){
            edge e = ed[j];
            if(p[e.from] != INF && p[e.to]> p[e.from]+e.c+P){
                p[e.to] = p[e.from]+e.c+P;
            }
        }
    }

    vector<bool> neg(MAX_V,false);
    rep(i,V){
        rep(j,E){
            edge e = ed[j];
            if(p[e.from] != INF && p[e.to]> p[e.from]+e.c+P){
                p[e.to] = p[e.from]+e.c+P;
                neg[e.to] = true;
            }
            if(neg[e.from])neg[e.to] = true;
        }
    }

    if(neg[V])cout<<-1<<endl;
    else cout<<max(-p[V],0LL)<<endl; return 0;
}
