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

ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	string s;cin>>s;
	map<ll,ll> cnt;
	vector<int> sum(s.size()+1,0);
	cnt[0]++;
	rep(i,s.size()){
		int t = (s[s.size()-1-i]-'0') * rep_power_modM(10,i, 2019)%2019;
		sum[i+1] = (sum[i] + t)%2019;
		cnt[sum[i+1]]++;
	}
	ll ans = 0;
	for(auto x: cnt)ans += (ll)x.second*(x.second-1)/2;
	cout<<ans<<endl;
	return 0;
}