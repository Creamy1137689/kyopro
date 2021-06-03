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

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    set<int> ok;
    vector<int> sd;
    rep(i,9)sd.emplace_back(10*i + d);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        rep(i, sd.size()){
            if(t + sd[i] <= 10*d+9){
                q.push(t+sd[i]);
                ok.insert(t+sd[i]);
            }
        }
    }
    rep(i,10)ok.insert(10*d + i);
    rep(i,n){
        if(a[i] > 10*d + 9)cout << "yes" << endl;
        else {
            if(ok.count(a[i]) != 0)cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}
