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

ll A,B,X;

bool isOK(ll num){
    if(A*num + B*((int)log10(num)+1LL) <= X) return true;
    else return false;
}

ll binary_search(){
    ll ng = 1000000001LL;
    ll ok =-1LL;
    while(abs(ok-ng) > 1LL){
        ll mid = (ok + ng)/2LL;
        if(isOK(mid)){ok = mid;}
        else ng = mid;
    }
    return ok;
}

int main(){
	cin>>A>>B>>X;
	cout<<binary_search()<<endl;
	return 0;
}