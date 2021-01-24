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
	ll n, k, m, r;
	cin >> n >> k >> m >> r;
	vector<int> score(n-1);
	rep(i,n-1)cin>>score[i];
	if(n == 1){
		cout<<r<<endl;
		return 0;
	}
	sort(all(score));
	ll sum = 0; 
	rep(i,k-1)sum += score[n-2-i];
	if(sum + score[n-1-k] >= r*k){
		cout<<0<<endl;
		return 0;
	}
	ll need = r*k - sum;
	if(need > m){
		cout<<-1<<endl;
	}else{
		cout<<need<<endl;
	}
	return 0;
}
