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

bool isOK(int a[], int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int binary_search(int a[], int nax, int key){
    int ng = -1;
    int ok =nax;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(a,mid,key))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	int N; cin>>N;
	int L[2020];
	rep(i,N)cin>>L[i];
	sort(L,L+N);
	ll ans = 0;
	rep(i,N){
		for(int j = i+1; j<N; ++j){
			int r = binary_search(L,N,L[i]+L[j]);
			int l = binary_search(L,N,abs(L[i]-L[j])+1);
			int e_ans = r-l;
			if(r>i && i>=l)--e_ans;
			if(r>j && j>=l)--e_ans;
			// printf("[i,j]->[%d,%d] [min,max]->[%d,%d] [l,r]->[%d,%d] [e_ans]->[%d]\n"
			// 	,L[i], L[j], L[j]-L[i], L[i]+L[j], l,r,e_ans);
			ans += e_ans;
		}
	}
	cout<<ans/3<<endl;
	return 0;
}