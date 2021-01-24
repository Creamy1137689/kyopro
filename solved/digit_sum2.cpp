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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	string N; cin>>N;
	bool nat = true;
	REP(i,N.size()-1){
		if(N[i] != '9')nat = false;
	}
	if(nat){
		cout<<9*(N.size()-1) + N[0] - '0'<<endl ; return 0;
	}
	int ans = (N.size()-1)*9 + N[0] - '1';
	cout<<ans<<endl; 
	return 0;
}