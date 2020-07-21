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
#define show(obj) {for(auto x:obj)cout<<x<<' ';}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int N, K;
vector<vector<int>> code(5, vector<int> (5));
bool ans = true;

void solve(vector<int> a){
	if(a.size() == N){
		int t = 0;
		for(auto x: a)t = (t^x);
		if(t == 0)ans = false;
		//show(a);
		//printf("[xor = %d]\n", t);
	}else{
		rep(i,K){
			vector<int> n = a;
			n.push_back(code[a.size()][i]);
			solve(n);
		}
	}
}

int main(){
	cin >> N >> K;
	rep(i,N)rep(j,K)cin>>code[i][j];
	solve(vector<int>());
	cout << ((ans)?"Nothing":"Found") << endl;
	return 0;
}
