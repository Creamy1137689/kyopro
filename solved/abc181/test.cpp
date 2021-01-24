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

ll solve(int N, int M, vector<ll> h, vector<ll> w){
    sort(all(h));
    vector<ll> dif_front(N/2);
    vector<ll> dif_back (N/2);
    rep(i,N/2){
        dif_front[i] = abs(h[2*i] - h[2*i + 1]);
    }
    sort(all(h), greater<ll>());
    rep(i,N/2){
        dif_back[i] = abs(h[2*i] - h[2*i + 1]);
    }
    sort(all(h));
    vector<ll> sum_df(N/2+1, 0);
    vector<ll> sum_db(N/2+1, 0);
    rep(i,N/2)sum_df[i+1] = sum_df[i] + dif_front[i];
    rep(i,N/2)sum_db[i+1] = sum_db[i] + dif_back[i];
    ll ans = INF;
    rep(i,M){
        auto it = lower_bound(all(h), w[i]);
        int pos = it - h.begin();
        ll tmp = 0;
        if(pos % 2 == 1){
            tmp += sum_df[pos/2];
            tmp += sum_db[(N-pos)/2];
            tmp += abs(w[i] - h[pos-1]);
        }else{
            tmp += sum_df[pos/2];
            tmp += sum_db[(N-pos)/2];
            tmp += abs(w[i] - h[pos]);
        }
        ans = min(ans, tmp);
    }
    return ans;
}

ll naive(int N, int M, vector<ll> h, vector<ll> w){
    ll ans = INF;
    rep(i,M){
        vector<ll> hhh = h;
        hhh.push_back(w[i]);
        sort(all(hhh));
        ll tmp = 0;
        rep(j,(N+1)/2)tmp += abs(hhh[2*j] - hhh[2*j+1]);
        ans = min(ans, tmp);
    }
    return ans;
}


int main(){
    random_device seed_gen;
	mt19937 engine(seed_gen());
    int T; 
    cin >> T;
    int N = 7, M = 7;
    vector<ll> h(N), w(M);
    REP(i,T){
        rep(j,N)h[j] = seed_gen()%50+1;
        rep(j,M)w[j] = seed_gen()%50+1;
        ll ans1 = solve(N, M, h, w);
        ll ans2 = naive(N, M, h, w);
        if(ans1 != ans2){
            cout << line << endl;
            printf("[test : %d] -> [solve : %lld, naive : %lld]\n", i, ans1, ans2);
            show(h);show(w);
            cout << line << endl;
        }
    }
    return 0;
}
