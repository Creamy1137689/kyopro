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
const int MOD = 1234567;

class rsq_seg{
    const int MAX_SEG;
    int seg_len;
    vector<ll> segtree;
    public:
        rsq_seg(int N, int def) : MAX_SEG(5000000), segtree(MAX_SEG), seg_len(1){
            while(seg_len < N)seg_len *= 2;
            rep(i,MAX_SEG)segtree[i] = def;
        }

        void update(int l, int r, int k){
        	l += seg_len-1;
        	r += seg_len-1;
        	while(l<r){
        		if(l % 2 == 1){segtree[l] += k; segtree[l] %= MOD; ++l;}
        		l /= 2;
        		if(r % 2 == 1){segtree[r-1] += k; segtree[r-1] %= MOD; --r;}
        		r /= 2;
        	}
        }

        ll get(int k){
            k += seg_len-1;
            ll res = 0;
            while(k > 0){
                res += segtree[k];
                res %= MOD;
                k /= 2;
            }
            return res;
        }
};

int main(){
    ll N, P;
    cin >> N >> P;
    vector<ll> h(N);
    vector<ll> lm(N);
    rep(i,N)cin >> h[i];
    ll sum = 0;
    ll ind = 0;
    rep(i,N){
        if(i != 0)sum -= h[i-1];
        while(sum + h[ind] <= P && ind < N){
            sum += h[ind];
            ++ind;
        }
        lm[i] = ind;
    }
    rsq_seg seg(N+3, 0);
    seg.update(1, 2, 1);
    rep(i,N){
        ll way = seg.get(i+1);
        seg.update(i + 2, lm[i] + 2, way);
    }
    cout << seg.get(N+1) << endl;
    return 0;
}
