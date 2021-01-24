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

int main(){
    int N = 20;
    int K = 100;
    vector<P> card(K+1);
    card[0].first = 0; card[0].second = 0;
    REP(i,K)cin >> card[i].first >> card[i].second;
    string ans;
    rep(i,K){
        if(card[i].first < card[i+1].first){
            ans += string(abs(card[i].first - card[i+1].first), 'D');
        }else{
            ans += string(abs(card[i].first - card[i+1].first), 'U');
        }
        if(card[i].second < card[i+1].second){
            ans += string(abs(card[i].second - card[i+1].second), 'R');
        }else{
            ans += string(abs(card[i].second - card[i+1].second), 'L');
        }
        ans += 'I';
    }
    cout << ans << endl;
    return 0;
}
