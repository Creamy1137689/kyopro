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
	int m;
	cin>>m;
	vector<ip> find(m);
	rep(i,m)cin>>find[i].first>>find[i].second;
	for(int i = 1; i<m; ++i){
		find[i].first = find[i].first-find[0].first;
		find[i].second = find[i].second-find[0].second;
	}
	int n;
	cin>>n;
	vector<ip> sky(n);
	rep(i,n)cin>>sky[i].first>>sky[i].second;
	set<ip> mms;
	rep(i,n){
		mms.insert(make_pair(sky[i].first, sky[i].second));
	}
	rep(i,n){
		int x = sky[i].first, y = sky[i].second;
		bool ok = true;
		for(int i = 1; i<m; i++){
			int dx = x + find[i].first;
			int dy = y + find[i].second;
			if(mms.count(make_pair(dx,dy)))continue;
			else {
				ok = false; break;
			}
		}
		if(ok){cout<<x-find[0].first<<' '<<y-find[0].second<<endl; return 0;}
	}
	return 0;
}
