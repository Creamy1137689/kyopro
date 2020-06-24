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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int x,N; cin>>x>>N;
	vector<bool> R(1000,true);
	int t;
	rep(i,N){
		cin>>t;
		R[t+500] = false;
	}
	int md = inf;
	int dif;
	int ans;
	rep(i,1000){
		if(R[i] == true){
			t = i-500;
			dif = abs(t-x);
			if(dif < md){
				md = dif;
				ans = t;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}