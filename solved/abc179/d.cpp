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
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = 998244353;

ll seg_len = 1;
vector<ll> seg(10000000,0LL);

//1-indexedのl,rを入れる
//区間は[l,r)であることに注意
void add(ll l, ll r, ll x){
	l += seg_len-1;
	r += seg_len-1;
	while(l<r){
		if(l % 2 == 1){seg[l] += x; seg[l] %= MOD; ++l;}
		l /= 2;
		if(r % 2 == 1){seg[r-1] += x; seg[r] %= MOD; --r;}
		r /= 2;
	}
}

//1-indexedで入れる
ll get(ll i){
	ll k = i+seg_len-1;
	ll res = 0;
	while(k>0){
		res += seg[k];
        res %= MOD;
		k /= 2;
	}
	return res;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<P> range(K);
    rep(i,K)cin >> range[i].first >> range[i].second;
    rep(i,K) ++range[i].second;
    while(seg_len < N)seg_len *= 2;
    add(1,2,1);
    for(int i = 1; i < N; ++i){
        ll tmp = get(i);
        rep(j,K){
            add(i + range[j].first, i + range[j].second, tmp);
        }
        //REP(j,N)cout << get(j)<< ' ';
        //cout << endl;
    }
    cout << get(N) << endl;
    return 0;
}
