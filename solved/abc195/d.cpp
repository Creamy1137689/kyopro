#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

bool comp(P a, P b){
    return a.second > b.second;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<P> item(n);
    rep(i,n)cin >> item[i].first >> item[i].second;
    sort(all(item), comp);
    vector<int> box(m);
    rep(i,m)cin >> box[i];
    while(q-- > 0){
        int l, r;
        int res = 0;
        cin >> l >> r;
        --l;
        vector<int> usebox;
        rep(i,l)usebox.emplace_back(box[i]);
        for(int i = r; i < m; ++i)usebox.emplace_back(box[i]);
        sort(all(usebox));
        vector<bool> used(usebox.size(), false);
        rep(i,n){
            int val = item[i].second;
            int wei = item[i].first;
            rep(j,usebox.size()){
                if(usebox[j] >= wei && !used[j]){
                    res += val;
                    used[j] = true;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
