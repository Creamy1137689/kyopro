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
	ll N; cin>>N;
	vector<int> node(N+1);
	rep(i,N+1)cin>>node[i];

	//can or not
	ll can = 1;
	int i = 0;
	while(i<=N && can<10000000000){
		if(node[i]>can){
			cout<<-1<<endl;
			return 0;
		}
		can -= node[i];
		can *= 2;
		++i;
	}
	if(node[N] == 0){cout<<-1<<endl; return 0;}

	//ans
	ll ans = N+1;
	vector<ll> used(N+1, 1);
	rep(i,N+1)used[i] += node[i];
	int rt = 1;
	node[N] --;
	show(used);
	for(int i = N; i>0; --i){
		if(rt > i){break; }
		cout<<node[i]<<endl;
		if(node[i] == 0)continue;
		while(node[i] > 0){
			ll can_use = pow(2,rt)-used[rt];
			if(node[i] < can_use){
				used[rt] += node[i];
				ans += node[i] * (i-rt+1);
				node[i] = 0;
			}else{
				used[rt] += can_use;
				node[i] -= can_use;
				ans += can_use * (i-rt+1);
				rt ++;
			}
		}
		show(used);
	}
	cout<<ans<<endl;
	return 0;
}