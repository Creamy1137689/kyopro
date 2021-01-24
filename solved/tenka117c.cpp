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
	ll N;
	cin>>N;
	ll h,n;
	for(h = 1; h<=3500; ++h){
		for(n = h; n<=3500; ++n){
			ll div = (4*h*n-N*n-N*h); 
			if(div == 0)continue;
			ll w = (N*h*n) / div;
			// printf("[%lld, %lld] -> %lld, %lld\n", h,n,div, w);
			if((N*h*n) % div == 0 && w > 0){
				printf("%lld %lld %lld\n", h, n, w);
				return 0;
			}
		}
	}
	return 0;
}