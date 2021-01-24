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

class rmq_seg{
    const int MAX_SEG;
    int seg_len;
    vector<int> segtree;
    public:
        rmq_seg(int N, int def) : MAX_SEG(10000000), segtree(MAX_SEG), seg_len(1){
            while(seg_len < N)seg_len *= 2;
            rep(i,MAX_SEG)segtree[i] = def;
        }

        void update(int l, int r, int k){
        	l += seg_len-1;
        	r += seg_len-1;
        	while(l<r){
        		if(l % 2 == 1){segtree[l] = min(segtree[l], k); ++l;}
        		l /= 2;
        		if(r % 2 == 1){segtree[r-1] = min(segtree[r-1], k); --r;}
        		r /= 2;
        	}
        }

        int get(int k){
            k += seg_len-1;
            int res = inf;
            while(k > 0){
                res = min(res, segtree[k]);
                k /= 2;
            }
            return res;
        }
};

int main(){
    ll N, Q, com, x;
    cin >> N >> Q;
    ll ans = (N-2)*(N-2);
    rmq_seg h(N, N-1), w(N, N-1);
    rep(_,Q){
        cin >> com >> x;
        --x;
        int to;
        if(com == 1){
            to = w.get(x);
            ans -= to-1;
            h.update(1, to+1, x);
        }else{
            to = h.get(x);
            ans -= to-1;
            w.update(1, to+1, x);
        }
        //printf("[ans = %d, to = %d]\n", ans , to);
    }
    cout << ans << endl;
    return 0;
}
