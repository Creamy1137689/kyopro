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
const ll MOD = 1e9 + 7;

int main(){
	string s; cin>>s;
	int N = s.size();
	string pure;
	vector<int> ind;
	rep(i,s.size()){
		if(s[i] != 'x'){pure.push_back(s[i]); ind.push_back(i);}
	}
	if(pure.size() == 0){cout<<0<<endl; return 0;}
	string pure_rev = pure; reverse(all(pure_rev));
	if(pure != pure_rev){
		cout<<-1<<endl; return 0;
	}
	int ans = 0;
	if(pure.size()%2 == 0){
		int left = ind[pure.size()/2-1];
		int right = ind[pure.size()/2];
		vector<int> lcnt;
		vector<int> rcnt;
		rep(i,left+1){
			int e = 0;
			while(s[i] == 'x'){ ++e; ++i;}
			lcnt.push_back(e);
		}
		for(int i = N-1; i>=right; --i){
			int e = 0;
			while(s[i] == 'x'){ ++e; --i;}
			rcnt.push_back(e);
		}
		rep(i,max(lcnt.size(),rcnt.size())){
			ans += abs(lcnt[i]-rcnt[i]);
		}
	}else{
		int bor = ind[pure.size()/2];
		vector<int> lcnt;
		vector<int> rcnt;
		rep(i,bor+1){
			int e = 0;
			while(s[i] == 'x'){ ++e; ++i;}
			lcnt.push_back(e);
		}
		for(int i = N-1; i>=bor; --i){
			int e = 0;
			while(s[i] == 'x'){ ++e; --i;}
			rcnt.push_back(e);
		}
		rep(i,max(lcnt.size(),rcnt.size())){
			ans += abs(lcnt[i]-rcnt[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}