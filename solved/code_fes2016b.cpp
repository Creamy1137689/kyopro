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
	int K,T; cin>>K>>T;
	map<int,int> cake;
	rep(i,T){
		int t; cin>>t;
		cake[i] = t;
	}
	int bf = inf;
	rep(i,K){
		if(cake.size() == 1){
			break;
		}
		int nax = 0;
		int ind;
		for(auto x:cake){
			if(x.second>nax && x.first != bf){
				ind = x.first;
				nax = x.second;
			}
		}
		--cake[ind];
		bf = ind;
		if(cake[ind] == 0){cake.erase(ind);}
	}
	for(auto x: cake)cout<<x.second-1<<endl;
	return 0;
}