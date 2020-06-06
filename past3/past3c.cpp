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

ll rep_power(ll a, ll n){
    if(n == 0)return 1;
    if(n%2 == 0){
    	ll tmp = rep_power(a,n/2);
    	if(tmp == -1 || tmp > 1000000000 || tmp*tmp > 1000000000)return -1;
    	return tmp*tmp;
    }
    a *= rep_power(a,n-1);
    if(a == -1)return -1;
    if(a>1000000000)return -1;
    return a;
}

int main(){
	ll a,r,n; cin>>a>>r>>n;
	ll t = rep_power(r,n-1LL);
	if(t <= -1){cout<<"large"<<endl; return 0;}
	// cout<<t<<endl;
	t *= a;
	if(t > 1000000000){cout<<"large"<<endl; return 0;}
	cout<<t<<endl;
	return 0;
}