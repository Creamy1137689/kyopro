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
	int N;
	cin >> N;
	int k = inf;
	for(int i = 2; i * (i - 1) <= 2*N; ++i){
		if(i * (i - 1) / 2 == N){
			k = i; break;
		}
	}
	if(k == inf){cout << "No" << endl; return 0;}
	else cout << "Yes" << endl;
	int num = 1;
	vector<set<int>> ans(k);
	rep(i,k){
		for(int j = i+1; j < k; ++j){
			ans[i].insert(num);
			ans[j].insert(num);
			++num;
		}
	}
	cout << ans.size() << endl;
	for(auto x:ans){
		cout << x.size() << ' ';
		show(x);
	}
	return 0;
}
