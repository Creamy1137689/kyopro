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

void enumerate_prime(vector<bool> &a){
    a[0] = false; a[1] = false;
    for(int i = 2; i*i<=a.size(); ++i){
        if(a[i]){ for(int j = 2; i*j<=a.size()-1; ++j){ a[i*j] = false; }}
    }
}

int main(){
	int N_MAX = 55556;
	vector<bool> primes(N_MAX,true);
	enumerate_prime(primes);
	int N; cin>>N;
	vector<int>ans(N);
	rep(i,N_MAX){
		if(N==0)break;
		if(primes[i] && i%5 == 1){
			--N;
			ans[N] = i;
		}
	}
	show(ans);
	return 0;
}