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
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<' ';
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n; cin>>n;
	vector<vector<int>> state(n,vector<int> (n,-1));
	rep(i,n){
		int k;cin>>k;
		rep(j,k){
			int x,y;
			cin>>x>>y;
			state[i][--x] = y;
		}
	}
	int ans = 0;
	for(int bit = (1<<n)-1; bit>0; --bit){
		vint t;
		vint al (n,-1);
		int cnt = 0;
		int p = 0;
		rep(i,n){
			if(bit & (1<<i)){
				++cnt;
				t.push_back(i);
				rep(j,n){
					if(state[i][j]==-1)continue;
					if(al[j] == -1)al[j] = state[i][j];
					else if(al[j] != state[i][j]){goto OUT;}
				}
			}
		}
		rep(i,n){
			if(i == t[p]){
				++p;
				if(al[i] == 0)goto OUT;
			}else{
				if(al[i] == 1)goto OUT;
			}
		}
		ans = max(ans,cnt);
		OUT:;
	}
	cout<<ans<<endl; return 0;
}
