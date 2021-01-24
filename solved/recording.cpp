#include <iostream>
#include <cassert>
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

int seg_len;
int seg[10000000] = {0};

//1-indexedのl,rを入れる
//区間は[l,r)であることに注意
void add(int l, int r, int x){
	l += seg_len-1;
	r += seg_len-1;
	while(l<r){
		if(l % 2 == 1){seg[l] += x; ++l;}
		l /= 2;
		if(r % 2 == 1){seg[r-1] += x; --r;}
		r /= 2;
	}
}

//1-indexedで入れる
int get(int i){
	int k = i+seg_len-1;
	int res = 0;
	while(k>0){
		res += seg[k];
		k /= 2;
	}
	return res;
}

int main(){
	int N, C, s, t, c;
	cin >> N >> C;
	seg_len = 1;
	while(seg_len < 200100)seg_len *= 2;
	rep(i,N){
		cin >> s >> t >> c;
		s *= 2; t *= 2;
		--s;
		add(s, t, 1);
	}
	int ans = -1; 
	rep(i,200050){
		ans = max(ans, get(i));
	}
	ans = min(ans, C);
	cout << ans << endl;
	return 0;
}
