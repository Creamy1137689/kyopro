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

int seg_len;
int seg[1000000];

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

int get(int i){
	int k = i+seg_len-1;
	int res = 0;
	while(k>0){
		res += seg[k];
		k /= 2;
	}
	return res;
}

bool check(int N){
	bool ans = true;
	rep(i,N)if(get(i) < N)ans = false;
	return ans;
}

int main(){
	int N,K; cin>>N>>K;
	seg_len = 1;
	while(seg_len <= N)seg_len *= 2;
	int a,l,r;
	rep(i,N){
		cin>>a;
		l = max(0, i-a);
		r = min(N-1, i+a)+1;
		add(l,r,1);
	}
	--K;
	vector<int> tmp(N);
	while(!check(N) && K>0){
		rep(i,N){
			tmp[i] = get(i);
		}
		rep(i,seg_len*2+10)seg[i] = 0;
		rep(i,N){
			int t = tmp[i];
			l = max(0, i-t);
			r = min(N-1, i+t)+1;
			add(l,r,1);
		}
		--K;
	}
	rep(i,N)cout<<min(get(i), N)<<endl;
	return 0;
}