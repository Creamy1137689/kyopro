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
#define show(obj) {for(auto x:obj)printf("[num:cnt]=[%d,%d]\n",x.first,x.second);}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N,M; cin>>N>>M;
	map<int,int> card;
	rep(i,N){
		int t; cin>>t;
		++card[t];
	}
	rep(i,M){
		int b,c;
		cin>>b>>c;
		for(auto x: card){
			if(x.first >= c)break;
			// cout<<line<<endl;
			// cout<<b<<' '<<c<<endl;
			// show(card);
			if(x.second > b){
				card[x.first] -= b; 
				card[c] += b;
				break;
			}
			card[c] += x.second;
			b -= x.second;
			card.erase(x.first);
			// cout<<line<<endl;
		}
	}
	ll ans = 0LL;
	for(auto x:card){
		// cout<<x.first<<endl;
		ans += (ll)x.first * x.second;
	}
	cout<<ans<<endl;
	return 0;
}