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

bool comp(P a, P b){
    int ra = a.first, rb = b.first;
    ra = min(ra, a.second);
    rb = min(rb, b.second);
    return ra < rb;
}

int main(){
    int N, a, b;
    cin >> N;
    vector<P> in;
    vector<bool> used(2*N+1,false);
    vector<P> nd;
    map<int, int> cnt;
    rep(i,N){
        cin >> a >> b;
        if(a == -1)a = inf;
        if(b == -1)b = inf;
        if(a != inf)used[a] = true;
        if(b != inf)used[b] = true;
        if(a == inf || b == inf)nd.push_back(make_pair(a,b));
        else in.push_back(make_pair(a,b));
        ++cnt[a]; ++cnt[b];
    }
    for(auto x: cnt)if(x.second > 1 && x.first != inf){
        cout << "No" << endl;
        return 0;
    }
    sort(all(nd), comp);
    bool ok = true;
    for(auto x:nd){
        if(x.first == x.second){
            int s = inf, e = inf;
            int i = 1;
            while(s == inf || e == inf){
                if(!used[i]){
                    if(s == inf)s = i;
                    else if(e == inf)e = i;
                    used[i] = true;
                }
                ++i;
            }
            in.push_back(make_pair(s,e));
        }else{
            if(x.first == inf){//-1 xみたいなとき→下に向かって探す
                bool changed = false;
                for(int i = 1; i < x.second; ++i){
                    if(!used[i]){
                        used[i] = true;
                        in.push_back(make_pair(i,x.second));
                        changed = true;
                        break;
                    }
                }
                //for(int i = x.second-1; i > 0; --i){
                //    if(!used[i]){
                //        used[i] = true;
                //        in.push_back(make_pair(i,x.second));
                //        changed = true;
                //        break;
                //    }
                //}
                if(!changed)ok = false;
            }else{//x -1みたいなとき→上に向かって探す
                bool changed = false;
                for(int i = x.first + 1; i <= 2*N; ++i){
                    if(!used[i]){
                        used[i] = true;
                        in.push_back(make_pair(x.first, i));
                        changed = true;
                        break;
                    }
                }    
                if(!changed)ok = false;            
            }
        }
    }
    vector<int> check(2*N + 1);
    rep(i,N){
        check[in[i].first] = i;
        check[in[i].second] = i;
    }
    rep(i,N){
        int me = in[i].second - in[i].first;
        for(int c = in[i].first + 1; c < in[i].second; ++c){
            int index = check[c];
            //printf("[i, c] = [%d, %d] with %d\n", i, c, 0);
            if(me != in[index].second - in[index].first)ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
