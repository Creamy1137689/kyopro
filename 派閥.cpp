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
	int n,m;
	cin>>n>>m;
	vector<vector<bool>> rel(15, vector<bool> (15,false));
	rep(i,m){
		int x,y;
		cin>>x>>y;
		--x; --y;
		rel[x][y] = true;
		rel[y][x] = true;
	}
	int ans = 0;
	for(int bit = 0; bit < (1<<n); bit++){
		vector<int> Q(n, -1);
		int index = 0;
		rep(i,n){
			if(bit & (1<<i)){
				Q[index++] = i;
			}
		}
		bool ok = true;
		for(int i = 0; i<index; ++i){
			for(int j = i+1; j<index; ++j){
				if(rel[Q[i]][Q[j]]){
					continue;
				}else{
					ok = false;
					break;
				}
			}
			if(!ok)break;
		}
		if(ok)ans = max(ans, index);
	}
	cout<<ans<<endl;
	return 0;
}
