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
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int op(int a, int b){return max(a,b);}

int e(){return 0;}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    segtree<int, op, e> seg(8000000);
    vector<int> ans(N);
    rep(i,N){
        ans[i] = seg.prod(max(0, a[i]-K), a[i] + K + 1) + 1;
        seg.set(a[i], ans[i]);
    }
    int res = 0;
    rep(i,N)res = max(res, ans[i]);
    cout << res << endl;
}

//class rmq_seg{
//    const int MAX_SEG;
//    ll seg_len;
//    vector<ll> segtree;
//    public:
//        rmq_seg(int N, int def) : MAX_SEG(30000000), segtree(MAX_SEG), seg_len(1){
//            while(seg_len < N)seg_len *= 2;
//            rep(i,MAX_SEG)segtree[i] = def;
//        }
//
//        void update(ll l, ll r, ll k){
//        	l += seg_len-1;
//        	r += seg_len-1;
//        	while(l<r){
//        		if(l % 2 == 1){segtree[l] = max(segtree[l], k); ++l;}
//        		l /= 2;
//        		if(r % 2 == 1){segtree[r-1] = max(segtree[r-1], k); --r;}
//        		r /= 2;
//        	}
//        }
//
//        ll get(ll k){
//            k += seg_len-1;
//            ll res = 0;
//            while(k > 0){
//                res = max(res, segtree[k]);
//                k /= 2;
//            }
//            return res;
//        }
//};
//
//int main(){
//    ll N, K;
//    cin >> N >> K;
//    vector<ll> a(N);
//    rep(i,N)cin >> a[i];
//    rmq_seg seg(8000000, 0);
//    vector<int> ans(N,0);
//    rep(i,N){
//        ans[i] = seg.get(a[i]+1) + 1;
//        seg.update(max(1LL, a[i] - K + 1), a[i] + K + 2LL, ans[i]);
//    }
//    cout << ans[N-1] << endl;
//    return 0;
//}
//