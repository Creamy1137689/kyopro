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

bool isOK(int a[], int index, int key){
    if(gcd(key,a[index]) == 1) return true;
    else return false;
}

int binary_search(int a[], int nax,int key){
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
	int N,Q;
	cin>>N>>Q;
	vector<int>a(N);
	vector<int>s(Q);
	rep(i,N)cin>>a[i];
	rep(i,Q)cin>>s[i];
	int gs[100010];
	gs[0] = a[0];
	for(int i = 1; i<N; ++i){
		gs[i] = gcd(gs[i-1], a[i]);
	}
	rep(i,Q){
		int ans = binary_search(gs, N,s[i]);
		if(ans == N){ans = gcd(s[i],gs[N-1]);}
		else ans++;
		cout<<ans<<endl;
	}
	return 0;
}