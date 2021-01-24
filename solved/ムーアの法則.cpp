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

long double P;

// 数値微分…fnは微分したい関数, xは座標, hは微小値(デフォルトで10^-9)
template<class Fn> long double differentiate(Fn fn, long double x, long double h = 0.00001){
    long double ans;
    ans = (fn(x+h)-fn(x-h))/(2*h);
    return ans;
}

long double func(long double x){
	return x + P/powl(2.0000, x/1.5L);
}

bool isOK(long double index, long double key){
    if(differentiate(func, index, 0.0000000001) >= key) return true;
    else return false;
}

long double binary_search(long double max, long double key){
    long double ng = 0LL;
    long double ok = max;
    while(abs(ok-ng) > 0.00000000001){
        long double mid = (ok + ng)/2.0;
        if(isOK(mid,key))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	cin>>P;
	long double ans_x;
	ans_x = binary_search(100LL, 0LL);
	cout<<fixed<<setprecision(10)<<func(ans_x)<<endl;
	return 0;
}