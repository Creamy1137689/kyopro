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

void solve(int N){
    int t, f, s;
    for(s = 0; s*7 <= N; ++s){
        for(f = 0; s*7+f*5 <= N; ++f){
            int k =s*7 + f*5;
            if((N-k)%3 == 0){
                cout << (N-k)/3 << ' ' << f << ' ' << s << endl;
                return;
            }
        }
    }
    cout << N << endl;
    return ;
}

int main(){
    int T; cin >> T;
    vector<int> ns(T);
    rep(i,T)ns[i] = 1000-i;
    rep(i,T)solve(ns[i]);
    return 0;
}
