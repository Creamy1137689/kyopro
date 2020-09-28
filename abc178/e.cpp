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

int guthoku(vector<P> &in){
	int res = 0;
	for(int i = 0; i < in.size(); ++i){
		for(int j = i + 1; j < in.size(); ++j){
			res = max(res, abs(in[i].first - in[j].first) + abs(in[i].second - in[j].second));
		}
	}	
	return res;
}

int main(){
	int N; cin >> N;
	vector<P> point(N);
	rep(i,N)cin >> point[i].first >> point[i].second;
	P dM = point[0], dm = point[0], uM = point[0], um = point[0];
	rep(i,N){
		ll dsum = point[i].first + point[i].second;
		ll usum = - point[i].first + point[i].second;
		if(dsum > dM.first + dM.second)dM = point[i];
		if(dsum < dm.first + dm.second)dm = point[i];
		if(usum > uM.second - uM.first)uM = point[i];
		if(usum < um.second - um.first)um = point[i];
	}
	int ans1 = abs(dM.first - dm.first) + abs(dM.second - dm.second);
	int ans2 = abs(uM.first - um.first) + abs(uM.second - um.second);
	cout << max(ans1, ans2) << endl;
	return 0;
}
