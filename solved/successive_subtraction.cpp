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
	priority_queue<ll, vector<ll>, greater<ll>> plus;
	priority_queue<ll> minus;
	ll a;
	rep(i,N){
		cin>>a;
		if(a >= 0)plus.push(a);
		else minus.push(a);
	}
	ll ans;
	vector<pair<ll, ll>> sets;
	ll x,y;
	if(minus.size() > 0){
		x = minus.top();
		minus.pop();
	}else{
		x = plus.top();
		plus.pop();
	}
	while(plus.size() > 1){
		y = plus.top();
		plus.pop();
		sets.push_back(make_pair(x, y));
		ans = x-y;
		x = ans;
	}
	if(plus.size()>= 1){
		sets.push_back(make_pair(plus.top(), x));
		ans = plus.top() - x;
		x = ans;
	}
	while(!minus.empty()){
		y = minus.top();
		minus.pop();
		sets.push_back(make_pair(x, y));
		ans = x-y;
		x = ans;
	}
	cout<<ans<<endl;
	for(auto x: sets){
		cout<<x.first<<' '<<x.second<<endl;
	}
	return 0;
}