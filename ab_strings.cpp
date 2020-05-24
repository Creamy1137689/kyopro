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
	ll N;cin>>N;
	ll head_b = 0, tail_a = 0, ab_cnt = 0, double_ab = 0;
	rep(i,N){
		string s; cin>>s;
		if(s[0] == 'B' && s[s.size()-1] == 'A') ++double_ab;
		else if(s[0] == 'B') ++head_b;
		else if(s[s.size()-1] == 'A') ++tail_a;
		rep(j,s.size()-1){	
			if(s[j] == 'A' && s[j+1] == 'B') ++ab_cnt;
		}
	}
	if((tail_a != 0 || head_b != 0) && double_ab>0){tail_a++; head_b++;}
	ll ans = ab_cnt + max(double_ab-1LL,0LL) + min(tail_a, head_b);
	cout<<ans<<endl;
	return 0;
}