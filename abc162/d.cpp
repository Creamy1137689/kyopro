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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n;
	string s;
	cin>>n>>s;
	vector<ll> R(n);
	vector<ll> G(n);
	vector<ll> B(n);
	for(int i = n-1; i> 0; --i){
		R[i-1] = R[i] + (s[i] == 'R');
		G[i-1] = G[i] + (s[i] == 'G');
		B[i-1] = B[i] + (s[i] == 'B');
	}
	ll ans = 0LL;
	for(int i = 0; i<n-2; ++i){
		if(s[i] == 'R')ans += G[i]*B[i];
		if(s[i] == 'G')ans += R[i]*B[i];
		if(s[i] == 'B')ans += G[i]*R[i];
	}
	for(int d = 0; 2*d+3<=n; ++d){
		for(int h = 0; d*2+3+h<=n; ++h){
			if(s[h] != s[h+d+1] && s[h+d+1] != s[h+2*d+2] && s[h]!=s[h+2*d+2])ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}