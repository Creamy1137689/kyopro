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

int seg_len = 1;
int seg[10000000];

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

int main(){
	int N,a,b; cin>>N;
	while(seg_len <= 1000000)seg_len *= 2;
	rep(i,N){
		cin>>a>>b;
		++a; b += 2;
		add(a,b,1);
	}
	int nax = 0;
	REP(i,1000010)nax = max(nax, get(i));
	cout<<nax<<endl;
	return 0;
}