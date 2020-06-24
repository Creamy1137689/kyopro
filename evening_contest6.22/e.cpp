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
#define show(obj) {for(auto x:obj)cout<<x.first<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

struct input{
	ll N;
	ll A;
	ll B;
	ll C;
	ll D;
};

void display(map<ll,ll> t){
	cout<<line<<endl;
	for(auto x:t){
		printf("[num : cost] -> [%lld : %lld]\n", x.first, x.second );
	}
	cout<<line<<endl;
}

ll spl_dist(ll D, ll to, ll from){
	ll t = abs(from-to);
	if(t < (1LL<<60)/D){
		return t*D;
	}else{
		return 1LL<<60;
	}
}

int main(){
	int T; cin>>T;
	int me[3] = {2,3,5};
	vector<input> ins(T);
	rep(i,T){
		cin>>ins[i].N>>ins[i].A>>ins[i].B>>ins[i].C>>ins[i].D;
	}
	ll N,D,ans;
	rep(q,T){
		N = ins[q].N; D = ins[q].D;
		ll costs[3] = {ins[q].A, ins[q].B, ins[q].C};
		map<ll,ll> nxt;
		ans = INF;
		nxt[N] = 0;
		ll n_cost, now, to, divd;
		while(nxt.size()>0){
			now = (*nxt.rbegin()).first;
			n_cost = (*nxt.rbegin()).second;
			nxt.erase(now);
			rep(i,3){
				divd = now/me[i] * me[i];
				to = divd;
				ll cs = n_cost + abs(to-now)*D;
				cs += costs[i];
				to /= me[i];
				if(to == 1)ans = min(ans, cs+D);
				else if(to == 0)ans = min(ans, cs);
				else{
					if(nxt.count(to) == 0){
						nxt[to] = cs;
						nxt[to] = min(nxt[to], n_cost+spl_dist(D, to, now));
					}else{
						nxt[to] = min(nxt[to], cs);
						nxt[to] = min(nxt[to], n_cost+spl_dist(D, to, now));
					}
				}

				to = divd+me[i];
				cs = n_cost + abs(to-now)*D;
				cs += costs[i];
				to /= me[i];
				if(to == 1)ans = min(ans, cs+D);
				else if(to == 0)ans = min(ans, cs);
				else if(to != now){
					if(nxt.count(to) == 0){
						nxt[to] = cs;
						nxt[to] = min(nxt[to], n_cost+spl_dist(D, to, now));
					}else{
						nxt[to] = min(nxt[to], cs);
						nxt[to] = min(nxt[to], n_cost+spl_dist(D, to, now));
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}