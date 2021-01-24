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

struct edge{int f,t; ll c;};
int V,E;
int MAX_E = 2020, MAX_V = 1010;

vector<edge> es(MAX_E);
vector<ll> d(MAX_V, INF);
vector<bool> n(MAX_V, false);

int main(){
    cin>>V>>E;
    rep(i,E){cin>>es[i].f>>es[i].t>>es[i].c; es[i].c *= -1;}

    d[1] = 0;
    for(int i = 0; i<V; ++i){
        rep(j,E){
            edge e = es[j];
            if(d[e.f] != INF && d[e.t]>d[e.f]+e.c){
                d[e.t] = d[e.f]+e.c;
            }
        }
    }

    for(int i = 0; i<V; ++i){
        rep(j,E){
            edge e = es[j];
            if(d[e.f] != INF && d[e.t]>d[e.f]+e.c){
                d[e.t] = d[e.f]+e.c;
                n[e.t] = true;
            }
            if(n[e.f])n[e.t] = true;
        }
    }

    if(n[V])cout<<"inf"<<endl;
    else cout<<-d[V]<<endl; return 0;

    //REP(i,V)cout<<"[V."<<i<<"] => "<<d[i]<<endl;
    
}
