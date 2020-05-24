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
	int H,W,N; cin>>H>>W>>N;
	vector<int> a;
	rep(i,N){
		int t; cin>>t;
		rep(j,t){
			a.push_back(i+1);
		}
	}
	vector<vector<int>> ans(H,vector<int> (W));
	rep(i,H){
		vector<int> e_ans(W);
		rep(j,W)e_ans[j] = a[i*W+j];
		if(i%2==1)reverse(all(e_ans));
		ans[i] = e_ans;
	}
	rep(i,H){show(ans[i]);}
	return 0;
}