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
#include<atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

struct st{
    int first;
    int second;
    int num;
};

bool comp(st a, st b){
    return a.first < b.first;
}

int main(){
    int N, a, b; 
    cin >> N;
    vector<st> town(N);
    rep(i,N){
        cin >> town[i].first >> town[i].second;
        town[i].num = i;
    }
    sort(all(town), comp);
    map<int,int> al;
    dsu uf(N);
    al[town[0].second] = 0;
    for(int i = 1; i < N; ++i){
        vector<int> erase_list;
        P minest = make_pair(inf, inf);
        for(auto x:al){
            if(x.first < town[i].second){
                uf.merge(i, x.second);
                erase_list.push_back(x.first);
                if(minest.first > x.first)minest = x;
            }else{
                break;
            }
        }
        for(auto x:erase_list){
            al.erase(x);
        }
        int push_pos = minest.second;
        if(minest.first > town[i].second){minest = make_pair(town[i].second, i); push_pos = i;}
        al[minest.first] = push_pos;
    }
    vector<int> ans(N);
    rep(i,N)ans[town[i].num] = uf.size(i);
    show(ans);
    return 0;
}
