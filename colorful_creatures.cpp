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

bool isOK(ll a[], int N, int index){
	bool ok = true;
	ll sum = a[index];
	rep(i,N){
		if(i == index)continue;
		if(a[i]<=sum*2){
			sum += a[i];
		}else{
			ok = false;
			break;
		}
	}
    if(ok) return true;
    else return false;
}

int binary_search(ll a[], int nax){
    int ng = -1;
    int ok =nax;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(a, nax, mid))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	int N; cin>>N;
	ll input[110010];
	rep(i,N)cin>>input[i];
	sort(input, input+N);
	int border = binary_search(input, N);
	cout<<N-border<<endl;
	return 0;
}