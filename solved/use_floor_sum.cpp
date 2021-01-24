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
#include<atcoder/all>
using namespace atcoder;
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

void solve(ll N, ll M, ll A, ll B){
    cout << floor_sum(N, M, A, B) << endl; 
}

int main(){
    int T;
    cin >> T;
    vector<ll> N(T);
    vector<ll> M(T);
    vector<ll> A(T);
    vector<ll> B(T);
    rep(i,T)cin >> N[i] >> M[i] >> A[i] >> B[i];
    rep(i,T)solve(N[i], M[i], A[i], B[i]);
    return 0;
}