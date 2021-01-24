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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N, K;
	cin >> N >> K;
	vector<int> V(N);
	rep(i,N)cin >> V[i];
	int ans = 0;
	for(int l = -1; l < N; ++l){
		for(int r = N; r > l; --r){
			vector<int> ac;
			//cout << l << ' ' << r << endl;
			rep(i,N){
				if(i <= l || r <= i)ac.push_back(V[i]);
			}
			int rest = K - ac.size();
			if(rest < 0)continue;
			sort(all(ac));
			while(rest > 0 && ac.size() > 0){
				if(ac[0] < 0)ac.erase(ac.begin());
				--rest;
			}
			int e_sum = 0;
			for(auto x:ac)e_sum += x;
			ans = max(ans, e_sum); 
		}
	}
	cout << ans << endl;
	return 0;
}
