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
	int n,m;
	cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<bool> ans(100000,false);
	for(int bit = 0; bit<(1<<n); ++bit){
		int e = 0;
		rep(i,n){
			if(bit & (1<<i)){
				e += a[i];
			}
		}
		ans[e] = true;
	}
	cin>>m;
	rep(i,m){
		int q;
		cin>>q;
		if(ans[q])cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}	
	return 0;
}
