#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n,m;
	cin>>n>>m;
	if(n>=m){cout<<0<<endl; return 0;}
	vint x(m);
	rep(i,m)cin>>x[i];
	sort(all(x));
	vint l(m-1);
	rep(i,m-1){
		l[i] = x[i+1]-x[i];
	}
	sort(all(l));
	ll nr = 0;
	for(int i = 1; i<=n-1; ++i){
		nr += l[m-i-1];
	}
	cout<<x[m-1]-x[0]-nr<<endl;
	return 0;
}
