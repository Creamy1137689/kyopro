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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int main(){
	int q;
	cin>>q;
	rep(i,q){
		string s, t;
		cin>>s>>t;
		vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, 0));
		REP(p,s.size()){
			REP(q,t.size()){
				int inc = 0;
				if(s[p-1] == t[q-1])inc = 1;
				chmax(dp[p][q], dp[p-1][q-1]+inc);
				chmax(dp[p][q], dp[p-1][q]);
				chmax(dp[p][q], dp[p][q-1]);
				if(dp[p][q] > min(p,q))dp[p][q] = min(p,q);
			}
		}
		/*
		cout<<"---------------"<<endl;
		rep(p, s.size()+1){
			rep(q, t.size()+1){
				cout<<dp[p][q];
			}
			cout<<endl;
		}*/
		cout<<dp[s.size()][t.size()]<<endl;
		//cout<<"---------------"<<endl;
	}
	return 0;
}