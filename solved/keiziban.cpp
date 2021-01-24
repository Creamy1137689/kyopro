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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N,M;
	cin >> N >> M;
	vector<bool> used(N,false);
	vector<int> ans;
	vector<int> input(M);
	rep(i,M)cin>>input[i];
	reverse(all(input));
	rep(i,M){
		int t = input[i];
		if(!used[t-1]){
			used[t-1] = true;
			ans.push_back(t);
		}
	}
	rep(i,N){
		if(!used[i]){
			ans.push_back(i+1);
		}
	}
	rep(i,N)cout<<ans[i]<<endl;
	return 0;
}
