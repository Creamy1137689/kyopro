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
	double n,k;
	cin>>n>>k;
	double ans = 0;
	REP(i,n){
		if(i>=k){ans += 1; continue;}
		int p = ceil(log(k/i)/log(2));
		ans += pow(0.5,p);
	}
	cout<<fixed<<setprecision(13)<<ans/n<<endl;
	return 0;
}