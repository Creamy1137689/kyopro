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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll rep_power_modM(ll a, ll n, ll M = MOD){
	if(n == 0)return 1;
	if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
	return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N;
	cin >> N;
	if(N == 1){
		cout << 0 << endl;
		return 0;
	}
	vector<ll> only0(N+1,0);
	vector<ll> only9(N+1,0);
	vector<ll> no(N+1,0);
	vector<ll> both(N+1,0);
	no[0] = 1;
	for(int i = 1; i <= N; ++i){
		rep(d,10){
			if(d == 0){
				only0[i] += no[i-1];
				only0[i] += only0[i-1];
				both[i] += only9[i-1];
			}else	if(d == 9){
				only9[i] += no[i-1];
				only9[i] += only9[i-1];
			 	both[i] += only0[i-1];	
			}else{
				only0[i] += only0[i-1];
				no[i] += no[i-1];
				only9[i] += only9[i-1];
			}
			both[i] += both[i-1];
			only9[i] %= MOD;
			only0[i] %= MOD;
			both[i] %= MOD;
			no[i] %= MOD;
		}
	}
	cout << both[N] << endl;	
	return 0;
}
