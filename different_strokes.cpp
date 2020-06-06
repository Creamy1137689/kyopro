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
	int N; cin>>N;
	vector<ll> a(N);
	vector<ll> b(N);
	rep(i,N)cin>>a[i]>>b[i];
	vector<pair<ll, int>> dish(N);
	rep(i,N){
		dish[i].first = a[i] + b[i];
		dish[i].second = i;
	}
	sort(all(dish), greater<pair<ll,int>>());
	ll sum_a = 0, sum_b = 0;
	rep(i,N){
		if(i % 2 == 0){
			sum_a += a[dish[i].second];
		}else{
			sum_b += b[dish[i].second];
		}
	}
	cout<<sum_a - sum_b<<endl;
	return 0;
}