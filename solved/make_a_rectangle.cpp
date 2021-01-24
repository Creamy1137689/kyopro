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
	int N;
	cin>>N;
	map<ll,ll> A;
	A[0LL] = 1LL;
	rep(i,N){
		ll a;
		cin>>a;
		A[a]++;
	}
	auto itr = --A.end();
	ll x = INF;
	for(; itr!=A.begin(); --itr){
		ll len = itr->first;
		ll cnt = itr->second;
		//cout<<len<<' '<<cnt<<endl;
		if(x == INF && cnt>=4LL){
			cout<<len*len<<endl;
			return 0;
		}
		if(cnt>=2LL){
			if(x == INF)x = len;
			else {
				cout<<len*x<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
	return 0;
}