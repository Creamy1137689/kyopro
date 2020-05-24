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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int n;
void dfs(string s, char mx){
	if(s.size() == n){
		cout<<s<<endl;
		return;
	}
	for(char c = 'a'; c<=mx+1; ++c){
		string t = s;
		t += c;
		dfs(t, max(mx,c));
	}
}

int main(){
	cin>>n;
	dfs("", 'a'-1);
	return 0;
}
