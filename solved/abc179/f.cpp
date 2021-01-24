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
    int N, Q, com, x;
    cin >> N >> Q;
    int h = N, w = N;
    ll ans = ((ll)N-2)*((ll)N-2);
    rep(_,Q){
        cin >> com >> x;
    }
}

//int main(){
//    ll N, Q, com, x;
//    cin >> N >> Q;
//    set<LP> tate, yoko;
//    tate.insert(make_pair(N,N));
//    yoko.insert(make_pair(N,N));
//    ll ans = (N-2)*(N-2);
//    rep(i,Q){
//        cin >> com >> x;
//        if(com == 1){
//            auto it = tate.lower_bound(make_pair(x, -inf));
//            ans -= (*it).second-2;
//            yoko.insert(make_pair((*it).second-1, x));
//        }else{
//            auto it = lower_bound(all(yoko), make_pair(x, -inf));
//            ans -= (*it).second-2;
//            tate.insert(make_pair((*it).second-1, x));
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
