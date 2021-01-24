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
	ll N; cin>>N;
	int len = 0;
	for(; pow(26,len) <= N; ++len){
		N -= pow(26,len);
	}
	vector<int> v(len,0);
	int cnt = 0;
	while(N>0){
		int x = N%26;
		// if(x == 0)x = 25;
		N /= 26;
		v[cnt++] = x;
	}
	reverse(all(v));
	rep(i,len){cout<<(char)('a'+v[i]);}
	cout<<endl;
	return 0;
}

// int main(){
// 	ll N; cin>>N;
// 	string ans;
// 	while(N>0){
// 		int x = N%26;
// 		if(x == 0)x = 26;
// 		char t = 'a' + (x-1);
// 		N /= 26;
// 		printf("[%lld... %d]\n", N, x);
// 	}
// 	reverse(all(ans));
// 	cout<<ans<<endl;
// 	return 0;
// }