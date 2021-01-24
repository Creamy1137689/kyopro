#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int N;
map<P, double> graph;

bool isOK(double r){
    dsu uf(N+2);
    for(auto x:graph){
        if(x.second < 2*r)uf.merge(x.first.first, x.first.second);
    }
    if(uf.same(N, N+1))return false;
    else return true;
}

double binary_search(){
    double ng = 100.5;
    double ok = 0;
    int cnt = 0;
    while(cnt < 80){
        double mid = (ok + ng)/2;
        if(isOK(mid))ok = mid;
        else ng = mid;
        ++cnt;
    }
    return ok;
}

double dif(P a, P b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){
    cin >> N;
    vector<P> d(200);
    rep(i,N)cin >> d[i].first >> d[i].second;
    rep(i,N){
        for(int j = i + 1; j < N; ++j){
            graph[make_pair(i,j)] = dif(d[i], d[j]);
        }
    }
    rep(i,N){
        graph[make_pair(i,N)] = abs(100-d[i].second);
    }
    rep(i,N){
        graph[make_pair(i,N+1)] = abs(-100-d[i].second);
    }
    cout << fixed << setprecision(10) << binary_search() << endl;
    return 0;
}
