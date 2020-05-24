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

int main(){
	string s,t;
	cin>>s>>t;
	map<char,int> se, te;
	vector<int> anss(s.size()), anst(t.size());
	int s_cnt = 0, t_cnt = 0;
	rep(i,s.size()){
		if(se.count(s[i])==0){
			anss[i] = s_cnt;
			se[s[i]] = s_cnt;
			++s_cnt;
		}else{
			anss[i] = se[s[i]];
		}
		if(te.count(t[i])==0){
			anst[i] = t_cnt;
			te[t[i]] = t_cnt;
			++t_cnt;
		}else{
			anst[i] = te[t[i]];
		}
	}
	rep(i,s.size()){
		if(anss[i]==anst[i])continue;
		else{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
