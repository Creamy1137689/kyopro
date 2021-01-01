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

int main(){
    int N; cin >> N;
    vector<int> a(N);
    vector<int> ideal(N);
    rep(i,N){
        cin >> a[i];
        ideal[i] = a[i];
    }
    sort(all(ideal));
    bool ans = false;
    bool tmp = true;
    rep(i,N)if(ideal[i] != a[i])tmp = false;
    ans = tmp;
    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            swap(a[i], a[j]);
            tmp = true;
            rep(i,N)if(a[i] != ideal[i])tmp = false;
            swap(a[i], a[j]);
            if(tmp)ans = true;
        }
    }
    cout << (ans ? "YES" : "NO" )  << endl;
    return 0;
}
