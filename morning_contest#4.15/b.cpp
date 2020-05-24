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
	vector<int> seg(6,0);
	int N; cin>>N;
	rep(i,N){
		double nax, nin;
		cin>>nax>>nin;
		if(nax>=35) ++seg[0];
		else if(30 <= nax && nax < 35) ++seg[1];
		else if(25 <= nax && nax < 30) ++seg[2];
		else if(nax < 0) ++seg[5];
		if(nin>=25) ++ seg[3];
		if(nin<0 && nax >= 0) ++seg[4];
	}
	rep(i,6){
		cout<<seg[i];
		if(i!=5)cout<<' ';
	}
	cout<<endl;
	return 0;
}