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
	string vote;
	cin>>vote;
	map<char,int> cnt;
	rep(i,vote.size()){
		cnt[vote[i]]++;
	}
	char ans;
	int nax = 0;
	for(auto x:cnt){
		if(nax < x.second){ans = x.first; nax = x.second;}
	}
	cout<<ans<<endl;
	return 0;
}