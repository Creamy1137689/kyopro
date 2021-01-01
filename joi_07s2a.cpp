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
        		if(l % 2 == 1){segtree[l] = max(segtree[l], k); ++l;}
        		l /= 2;
        		if(r % 2 == 1){segtree[r-1] = max(segtree[r-1], k); --r;}
        		r /= 2;
        	}
        }

        int get(int k){
            k += seg_len-1;
            int res = -1;
            while(k > 0){
                res = max(res, segtree[k]);
                k /= 2;
            }
            return res;
        }
};

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    rmq_seg seg(10010, 0);
    vector<int> dp(N);
    rep(i,N){
        dp[i] = seg.get(a[i]) + 1;
        seg.update(a[i] + 1, 10010, dp[i]);
    }
    int ans = -1;
    rep(i,N)ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
