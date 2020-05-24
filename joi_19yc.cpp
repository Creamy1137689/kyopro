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
	int N; string s; cin>>N>>s;
	int i = 0;
	int ans = 0;
	while(i<N-1){
		if((s[i]=='O'&&s[i+1]=='X') || (s[i]=='X'&&s[i+1]=='O')){
			++ans; i += 2;
		}else{
			++i;
		}
	}
	cout<<ans<<endl;
	return 0;
}