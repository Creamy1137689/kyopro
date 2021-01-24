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
	string s;cin>>s;
	for(int i= 2; i<s.size(); i += 2){
		string t = s.substr(0, s.size()-i);
		bool ok = true;
		rep(j,t.size()/2-1){
			if(t[j] == t[j + t.size()/2])continue;
			ok = false;
			break;
		}
		if(ok){
			cout<<s.size()-i<<endl;
			return 0;
		}
	}
	return 0;
}