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
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int n,c; cin>>n>>c;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	int ans = inf;
	REP(f,10){
		REP(s,10){
			if(f == s)continue;
			int e_ans = 0;
			rep(i,n){
				if(i%2 == 0){
					if(a[i] != f)++e_ans;
				}else{
					if(a[i] != s)++e_ans;
				}
			}
			ans = min(ans, e_ans);
		}
	}
	cout<<ans*c<<endl;
	return 0;
}