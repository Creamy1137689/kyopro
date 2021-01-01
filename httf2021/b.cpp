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

int nap[20][20];

bool iscont(P now, P to, P mid){
    int dist = abs(now.first - to.first) + abs(now.second - to.second);
    int d = abs(now.first - mid.first) + abs(now.second - mid.second) + abs(mid.first - to.first) + abs(mid.second - to.second);
    return dist >= d;
}

string route(P now, P to){
    string res;
    if(now.first < to.first){
        res += string(abs(now.first - to.first), 'D');
    }else{
        res += string(abs(now.first - to.first), 'U');
    }
    if(now.second < to.second){
        res += string(abs(now.second - to.second), 'R');
    }else{
        res += string(abs(now.second - to.second), 'L');
    }
    return res;
}


char inv(char c){
    if(c == 'R')return 'L';
    else if(c == 'L')return 'R';
    else if(c == 'U')return 'D';
    else return 'U';
}

bool check(P now, P to){
    if(now.second < to.second)if(nap[to.first][to.second-1] == 0)return true;
    if(now.second > to.second)if(nap[to.first][to.second+1] == 0)return true;
    return false;
}

int main(){
    int N = 20;
    int K = 100;
    vector<P> card(K+1);
    card[0].first = 0; card[0].second = 0;
    REP(i,K)cin >> card[i].first >> card[i].second;
    REP(i,K)nap[card[i].first][card[i].second] = 1;
    string ans;
    rep(i,K){
        bool prop = false;
        if(i < K-1){
            if(iscont(card[i], card[i+1], card[i+2]) && check(card[i+2], card[i+1])){
                prop = true;
                ans += route(card[i], card[i+2]);
                ans += 'I';
                ans += route(card[i+2], card[i+1]);
                char c = ans[ans.size()-1];
                ans[ans.size()-1] = 'O';
                ans.push_back(c);
                ans += 'I';
                ans.push_back(inv(ans[ans.size()-2]));
                ans += 'I';
                ans += ans[ans.size()-4];
                ++i;
                card[i+1] = card[i];
                continue;
            }
        }
        if(i == K-1 || !prop){
            ans += route(card[i], card[i+1]);
            ans += 'I';
        }
    }
    cout << ans << endl;
    return 0;
}

//                char c = ans[ans.size()-1];
//                ans[ans.size()-1] = 'O';
//                ans.push_back(c);
//                ans += 'I';
//                ans.push_back(inv(ans[ans.size()-2]));
//                ans += 'I';
//                ans += ans[ans.size()-4];