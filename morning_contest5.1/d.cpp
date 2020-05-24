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
	int N; cin>>N;
	string su, sb;
	cin>>su>>sb;
	ll ans;
	int i;
	if(su[0]!=sb[0]){
		i = 2;
		ans = 6;
	}else{
		i = 1;
		ans = 3;
	}
	while(i<N){
		if(su[i] != sb[i]){
			if(su[i-1]!=sb[i-1]){
				// cout<<"ff"<<endl;
				ans *= 3;
				ans%=MOD;
			}else{
				// cout<<"ft"<<endl;
				ans *= 2;
				ans%=MOD;
			}
			i+=2;
		}else{
			if(su[i-1] == sb[i-1]){
				ans *= 2;
				ans%=MOD;
				// cout<<"tt"<<endl;
			}else{
				// cout<<"tf"<<endl;
			}
			++i;
		}
	}
	if(ans<0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}