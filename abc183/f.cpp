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
#include <atcoder/all>
using namespace atcoder;
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

int main(){
    int N, Q, t, a, b, x, y, com;
    cin >> N >> Q;
    dsu uf(N);
    vector<map<int, int>> cl(N);
    vector<int> dns(N);
    rep(i,N){
        dns[i] = i;
        cin >> t;
        --t;
        cl[dns[uf.leader(i)]][t]++;
    }
    rep(_,Q){
        cin >> com;
        if(com == 1){
            cin >> a >> b;
            --a; --b;
            if(uf.same(a,b))continue;
            int to = dns[uf.leader(a)];
            int from = dns[uf.leader(b)];
            int into = uf.merge(a, b);
            if(cl[to].size() < cl[from].size())swap(to, from);
            for(auto x:cl[from]){
                cl[to][x.first] += x.second;
                cl[from][x.first] -= x.second;
            }
            dns[into] = to;
        }else{
            cin >> x >> y;
            --x; --y;
            int set_num = dns[uf.leader(x)];
            cout << cl[set_num][y] << endl;
        }

        //set<int> al;
        //rep(i,N){
        //    int l = dns[uf.leader(i)];
        //    if(al.count(l) == 0){
        //        al.insert(l);
        //        cout << line << endl;
        //        cout << l << endl;
        //        for(auto x:cl[l])printf("[%d] -> %d\n", x.first, x.second);
        //        cout << line << endl;
        //    }
        //}
    }
    return 0;
}
