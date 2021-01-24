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
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef tuple<int, int, int> tp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

vector<P> co(110);
int N;

bool check(int now, int to, int from){
    if(from == N)return true;
    int a = co[from].first - co[now].first;
    int b = co[from].second - co[now].second;
    int x = co[to].first - co[now].first;
    int y = co[to].second - co[now].second;
    int dot = a*x + b*y;
    //printf("[%d -> %d -> %d], [dot = %d]\n", from, now, to, dot);
    return dot <= 0;
}

int main(){
    int M, a, b, c;
    cin >> N >> M;
    vector<vector<P>> G(N, vector<P>());
    rep(i,N)cin >> co[i].first >> co[i].second;
    rep(i,M){
        cin >> a >> b >> c;
        --a; --b;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    vector<vector<int>> dist(N+1, vector<int>(N+1, inf));
	priority_queue<tp, vector<tp>, greater<tp>> Q;
    dist[0][N] = 0;
    Q.emplace(0, 0, N);
	while(!Q.empty()){
		int cost = get<0>(Q.top());
		int f = get<1>(Q.top());
        int b = get<2>(Q.top());
		Q.pop();
        if(dist[f][b] < cost)continue;
		for(auto t:G[f]){
			if(check(f, t.first, b) && dist[t.first][f] > cost + t.second){
				dist[t.first][f] = cost + t.second;
				Q.emplace(dist[t.first][f], t.first, f);
			}
		}
	}
    int ans = inf;
    rep(i,N)ans = min(ans, dist[1][i]);
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}
