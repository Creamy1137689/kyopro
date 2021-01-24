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
	vector<int> ans(s.size(), 0);
	int r_pos, l_pos;
	int cnt1 = 0, cnt0 = 0;
	rep(i,s.size()){
		if(i%2==0)++cnt0;
		else ++cnt1;
		if(i == s.size()-1)break;
		if(s[i] == 'R' && s[i+1] == 'L'){
			r_pos = i; l_pos = i+1;
		}
		if(s[i] == 'L' && s[i+1] == 'R'){
			if(r_pos%2 == 0){
				ans[r_pos] = cnt0;
				ans[l_pos] = cnt1;
			}else{
				ans[r_pos] = cnt1;
				ans[l_pos] = cnt0;
			}
			cnt0 = 0; cnt1 = 0;
		}
	} 
	if(r_pos%2 == 0){
		ans[r_pos] = cnt0;
		ans[l_pos] = cnt1;
	}else{
		ans[r_pos] = cnt1;
		ans[l_pos] = cnt0;
	}
	show(ans);
	return 0;
}
