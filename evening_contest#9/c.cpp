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
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> order(M);
	rep(i,M)cin>>order[i].first>>order[i].second;
	int ans = -1;
	int s = pow(10, N-1), e = pow(10, N)-1;
	if(s == 1)s = 0;
	for(; s<=e; ++s){
		bool ok = true;
		rep(i,M){
			int ind = order[i].first;
			int tar = (s/(int)pow(10,N-ind))%10;
			if(tar != order[i].second)ok = false;
		}
		if(ok){ans = s; break;}
	}
	cout<<ans<<endl;
	return 0;
}