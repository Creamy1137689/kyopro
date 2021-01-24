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
	ll A,B;
	cin>>A>>B;
	ll g = __gcd(A,B);
	map<ll,ll> com;
	com[1LL]++;
	for(ll i = 2LL; i*i<=g; ++i){
		while(g%i==0LL){
			com[i]++;
			g /= i;
		}
	}
	if(g != 1LL)com[g]++;
	cout<<com.size()<<endl;
	return 0;
}