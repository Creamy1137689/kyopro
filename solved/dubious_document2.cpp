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

string s,t;

bool is_sam(char x, char y){
	if(x == '?')return true;
	if(x == y)return true;
	return false;
}

string make_st(int pos){
	string ans;
	rep(i,s.size()){
		if(i==pos){ans+=t; i += t.size()-1;}
		else if(s[i]=='?')ans+='a';
		else ans+=s[i];
	}
	return ans;
}

int main(){
	cin>>s>>t;
	bool al = false;
	vector<string> ans;
	rep(i,s.size()-t.size()+1){
		for(int j = 0; j<t.size(); ++j){
			if(is_sam(s[i+j],t[j])){if(j == t.size()-1){ans.push_back(make_st(i)); al=true;}}
			else break;
		}
	}
	if(!al){cout<<"UNRESTORABLE"<<endl; return 0;}
	sort(all(ans));
	cout<<ans[0]<<endl;
	return 0;
}
