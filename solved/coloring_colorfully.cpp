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
	string s;
	cin>>s;
	int fb = 0, fw = 0;
	rep(i,s.size()){
		if(s[i]-'0' != i%2)fb++;
		if(s[i]-'0' != (i+1)%2)fw++;
	}
	cout<<min(fw,fb)<<endl;
	return 0;
}