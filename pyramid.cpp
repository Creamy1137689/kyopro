#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

bool check(int tx, int ty, int th, int x, int y, int h){
	int ph = max(th - abs(tx-x) - abs(ty-y), 0);
	if(ph == h)return true;
	else return false;
}

int main(){
	int n;
	cin>>n;
	vector<pair<pair<int,int>,int>> data(n);
	rep(i,n){
		cin>>data[i].first.first>>data[i].first.second>>data[i].second;
	}
	int x,y,h;
	rep(i,n){
		if(data[i].second>0){
			x = data[i].first.first;
			y = data[i].first.second;
			h = data[i].second;
			break;
		}
	}
	rep(tx,101){
		rep(ty,101){
			int th = h + abs(x-tx) + abs(y-ty);
			bool ok = true;
			rep(i,n){
				if(!check(tx, ty, th, data[i].first.first, data[i].first.second, data[i].second)){
					ok = false;
					break;
				}
			}
			if(ok){cout<<tx<<' '<<ty<<' '<<th<<endl; return 0;}
		}
	}
	return 0;
}
