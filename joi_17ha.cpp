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

class rsq_seg{
    const int MAX_SEG;
    int seg_len;
    vector<ll> segtree;
    public:
        rsq_seg(int N, int def) : MAX_SEG(1000000), segtree(MAX_SEG), seg_len(1){
            while(seg_len < N)seg_len *= 2;
            rep(i,MAX_SEG)segtree[i] = def;
        }

        void update(int l, int r, int k){
        	l += seg_len-1;
        	r += seg_len-1;
        	while(l<r){
        		if(l % 2 == 1){segtree[l] += k; ++l;}
        		l /= 2;
        		if(r % 2 == 1){segtree[r-1] += k; --r;}
        		r /= 2;
        	}
        }

        ll get(int k){
            if(k == 0)return 0;
            k += seg_len-1;
            ll res = 0;
            while(k > 0){
                res += segtree[k];
                k /= 2;
            }
            return res;
        }
};

int main(){
    ll N, Q, S, T, l, r, x;
    cin >> N >> Q >> S >> T;
    S *= -1;
    ll ans = 0;
    vector<ll> a(N+1, 0);
    rsq_seg seg(N, 0);
    rep(i,N+1){
        cin >> a[i];
        if(i == 0)continue;
        seg.update(i, i + 1, a[i]);
    }
    rep(i,N)ans += (a[i] < a[i+1] ? S : T) * abs(a[i] - a[i+1]);
    rep(i,Q){
        cin >> l >> r >> x;
        ++r;
        ans += (seg.get(l-1) < seg.get(l) ? -S : -T) * abs(seg.get(l-1) - seg.get(l));
        if(r <= N){
            ans += (seg.get(r-1) < seg.get(r) ? -S : -T) * abs(seg.get(r-1) - seg.get(r));
        }
        seg.update(l, r, x);
        ans += (seg.get(l-1) < seg.get(l) ? S : T) * abs(seg.get(l-1) - seg.get(l));
        if(r <= N){
            ans += (seg.get(r-1) < seg.get(r) ? S : T) * abs(seg.get(r-1) - seg.get(r));
        }
        cout << ans << endl;
    }
    return 0;
}
