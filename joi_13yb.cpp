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
	int N; cin>>N;
	vector<vector<int>> in(N,vector<int>(3));
	rep(i,N){
		cin>>in[i][0]>>in[i][1]>>in[i][2];
	}
	vector<int> sum(N,0);
	rep(i,3){
		vector<int> ok(200,0);
		rep(j,N){
			ok[in[j][i]] ++;
		}
		rep(j,N){
			if(ok[in[j][i]] == 1){
				sum[j] += in[j][i];
			}
		}
	}
	rep(i,N)cout<<sum[i]<<endl;
	return 0;
}