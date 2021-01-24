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

int to[220] = {0};

void k_cut(int a[], int N, int k){
	for(int i = k; i<2*N; ++i)to[i-k] = a[i];
	rep(i,k)to[i+2*N-k] = a[i];
	rep(i,2*N)a[i] = to[i];
}

void shuffule(int a[], int N){
	rep(i,N){
		to[i*2] = a[i];
		to[i*2+1] = a[i+N];
	}
	rep(i,2*N)a[i] = to[i];
}

int main(){
	int N,M; cin>>N>>M;
	int a[220];
	rep(i,2*N){
		a[i] = i+1;
	}
	rep(i,M){
		int q; cin>>q;
		if(q == 0)shuffule(a,N);
		else k_cut(a,N,q);
	}
	rep(i,2*N){cout<<a[i]<<endl;}
	return 0;
}