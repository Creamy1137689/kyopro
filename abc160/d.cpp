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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	--x; --y;
	vector<vector<int>> dis(n,vector<int>(n,inf));
	rep(i,n){
		queue<int> Q;
		Q.push(i);
		dis[i][i] = 0;
		while(!Q.empty()){
			int now = Q.front();
			Q.pop();
			if(dis[i][now-1] == inf && now-1>=0){
				dis[i][now-1] = dis[i][now]+1;
				Q.push(now-1);
			}
			if(dis[i][now+1] == inf && now+1 <n){
				dis[i][now+1] = dis[i][now]+1;
				Q.push(now+1);
			}
			if(now == x && dis[i][y] == inf){
				dis[i][y] = dis[i][now]+1;
				Q.push(y);
			}
			if(now == y && dis[i][x] == inf){
				dis[i][x] = dis[i][now]+1;
				Q.push(x);
			}
		}
	}/*
	cout<<"pj"<<endl;
	rep(i,n){
		rep(j,n){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"pp"<<endl;*/
	vector<vector<int>> cnt(n,vector<int>(n,0));
	//cout<<"bbbb"<<endl;
	rep(i,n){
		rep(j,n){
			++cnt[i][dis[i][j]];
		}
	}
	/*
	cout<<"pj"<<endl;
	rep(i,n){
		rep(j,n){
			cout<<cnt[i][j]<<' ';
		}
		cout<<endl;
	}*/
	REP(k,n-1){
		ll ans = 0;
		rep(i,n){
			ans += cnt[i][k];
		}
		cout<<ans/2<<endl;
	}
	/*
	REP(k, n-1){
		int ans = 0;
		for(int i = 1; i+k<=n; ++i){
			for(int j = i+k; j<=n; ++j){
				if(abs(i-x) + abs(j-y) + 1 >= k)ans++;
			}
		}
		cout<<ans<<endl;
	}*/
	return 0;
}