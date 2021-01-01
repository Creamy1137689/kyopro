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
    int N;
    cin >> N;
    vector<char> v(N);
    rep(i,N)cin >> v[i];
    vector<set<int>> pos(26, set<int>());
    rsq_seg seg(N + 2,0);
    rep(i,N){
        int c = v[i]-'a';
        pos[c].insert(i+1);
    }
    //for(auto x:pos)if(x.size() > 0){for(auto y:x)cout << y << ' '; cout << endl;}
    vector<char> tar = v;
    reverse(all(tar));
    ll ans = 0;
    rep(i,N){
        int tar_char = tar[i]-'a';
        int p = *(pos[tar_char].begin());
        pos[tar_char].erase(pos[tar_char].begin());
        ans += p - seg.get(p) - 1;
        seg.update(p + 1, N + 1, 1);
    }
    cout << ans << endl;
    return 0;
}
