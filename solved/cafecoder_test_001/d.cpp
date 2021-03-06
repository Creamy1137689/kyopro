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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

map<int,int> primefactor(ll N){
    map<int,int> res;
    for(ll k = 2; k*k <= N; ++k){
        while(N % k == 0){res[k]++; N /= k;}
    }
    if(N != 1)res[N]++;
    return res;
}

int main(){
    ll N;
    cin >> N;
    map<int,int> facts = primefactor(N);
    ll a = 1, b = 1;
    for(auto x:facts){
        a *= pow(x.first, x.second/2);
        if(x.second % 2 == 1)b *= x.first;
    }
    if(b == 1)cout << a << endl;
    else cout << a << ' ' << b << endl;
    return 0;
}
