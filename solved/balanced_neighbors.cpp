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
	int ng = ((N % 2)? N:N+1);
	vector<P> ans;
	REP(i,N){
		for(int j = i+1; j <= N; ++j){
			if(j == ng-i)continue;
			ans.push_back(make_pair(i,j));
		}
	}
	cout << ans.size() << endl;
	for(auto x:ans){
		cout << x.first << ' ' << x.second << endl;
	}
	return 0;
}