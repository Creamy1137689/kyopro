#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class S, bool(*op)(S, S)>
struct sparse_table{
    private:
        vector<vector<int>> table;
        vector<S> d;
        vector<int> logtable;

    public:
        explicit sparse_table(vector<S>& a){
            d = a;
            logtable.resize(a.size()+1);
            logtable[0] = 0; logtable[1] = 0;
            for(int i = 2; i <= a.size(); ++i){
                logtable[i] = logtable[i >> 1] + 1;
            }
            table.resize(a.size(), vector<int>(logtable[a.size()] + 1));
            for(int i = 0; i < a.size(); ++i){
                table[i][0] = i;
            }
            for(int k = 1; (1 << k) <= a.size(); ++k){
                for(int i = 0; i + (1 << k) <= a.size(); ++i){
                    int fir = table[i][k-1], sec = table[i + (1 << (k-1))][k-1];
                    table[i][k] = (op(d[fir], d[sec])) ? fir : sec;
                }
            }
        }

        S prod(int l, int r){
            int k = logtable[r-l];
            return op(d[table[l][k]], d[table[r-(1<<k)][k]]) ?
                d[table[l][k]] : d[table[r-(1 << k)][k]];
        }

        int prod_ind(int l, int r){
            int k = logtable[r-l];
            return op(d[table[l][k]], d[table[r-(1<<k)][k]]) ?
                table[l][k] : table[r-(1 << k)][k];
        }

};
bool op(int a, int b){return a < b;}

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> a(m);
    vector<int> room(n+1, 0);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        --l;
        a[i] = make_pair(l, r);
        ++room[l];
        --room[r];
    }
    REP(i,n)room[i] += room[i-1];
    sparse_table<int, op> sp(room);
    int ans = 0;
    vector<int> ansa;
    rep(i,m){
        if(sp.prod(a[i].first, a[i].second) > 1){++ans; ansa.emplace_back(i+1);}
    }
    cout << ans << endl;
    rep(i,ansa.size()){
        cout << ansa[i] << endl;
    }
    return 0;
}
