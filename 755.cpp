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

int ans = 0;
ll n;

int cnt_k(string s){
	set<char> st;
	rep(i,s.size())st.insert(s[i]);
	return st.size();
}

void dfs(string s){
	if(s.size()>11)return ;
	if(atoll(s.c_str())>n)return;
	if(cnt_k(s)==3){ans++;}
	dfs(s+'7'); dfs(s+'3'); dfs(s+'5');
}

int main(){
	cin>>n;
	dfs("");
	cout<<ans<<endl;
}
