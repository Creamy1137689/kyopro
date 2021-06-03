#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int max_height = 0;
    int height = 1;
    vector<int> tops;
    a.emplace_back(-inf);
    rep(i,n){
        if(a[i] > a[i+1]){
            if(max_height < height){
                tops = vector<int>();
                tops.emplace_back(i);
                max_height = height;
            }else if(max_height == height){
                tops.emplace_back(i);
            }
            height = 0;
        }
        ++height;
    }
    a.pop_back();
    reverse(all(a));
    a.emplace_back(-inf);
    rep(i,n){
        if(a[i] > a[i+1]){
            if(max_height < height){
                tops = vector<int>();
                tops.emplace_back(i);
                max_height = height;
            }else if(max_height == height){
                tops.emplace_back(i);
            }
            height = 0;
        }
        ++height;
    }
    a.pop_back();
    bool ok = true;
    if(tops.size() > 2)cout << 0 << endl;
    else if(tops.size() == 2){
        if(tops[0] != tops[1])ok = false;
    }
    if(ok){
        if(max_height % 2)cout << 1 << endl;
        else cout << 0 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
