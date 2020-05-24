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
#define show(obj) {for(auto x:obj)cout<<x.W<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

struct colors{
	int W = 0;
	int R = 0;
	int B = 0;
};

int main(){
	int N,M; cin>>N>>M;
	vector<colors> flag(N);
	rep(i,N){
		rep(j,M){
			char c; cin>>c;
			if(c == 'W')flag[i].W++;
			if(c == 'R')flag[i].R++;
			if(c == 'B')flag[i].B++;
		}
	}
	int ans = inf;
	for(int w = 1; w<N; ++w){
		for(int b = 1; w+b<N; ++b){
			int e_ans = 0;
			rep(i,w)e_ans += M-flag[i].W;
			for(int i = w; i<w+b; ++i)e_ans += M-flag[i].B;
			for(int i = b+w; i<N; ++i)e_ans += M-flag[i].R;
			ans = min(ans, e_ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}