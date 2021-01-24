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

int popcount(ll t){
	int res = 1;
	while(t > 0){
		ll k = t;
		int e_res = 0;
		while(k>0){
			if(k % 2 == 1)++e_res;
			k /= 2;
		}
		t %= e_res;
		++res;
	}
	return res;
}

int main(){
	int n; cin>>n;
	string s; cin>>s;
	int res = 0;
	rep(i,n){
		res += pow(2,n-1-i)*(s[i] == '1');
	}
	cout<<res<<endl;
	cout<<res%14<<endl;
	return 0;
}