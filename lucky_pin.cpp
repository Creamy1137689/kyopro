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
#define all(x) begin(perm),end(perm)
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
	int n;cin>>n;
	string s; cin>>s;
	//cout<<"PPP"<<endl;
	vector<bool> so(10,false);
	vector<int> fom(n);
	fom[n-1] = 1;
	so[s[s.size()-1]-'0'] = true;
	for(int i = s.size()-2; i>=0; --i){
		if(!so[s[i]-'0']){
			fom[i] = fom[i+1]+1;
			so[s[i]-'0'] = true;
		}else{
			fom[i] = fom[i+1];
		}
	}
	vector<bool> al(110,false);
	int ans = 0;
	rep(i,n-2){
		for(int j = i+1; j<n-1; j++){
			int ch = (s[i]-'0')*10+s[j]-'0';
			if(!al[ch]){ans += fom[j+1]; al[ch] = true;}
		}
	}
	cout<<ans<<endl; return 0;
}
