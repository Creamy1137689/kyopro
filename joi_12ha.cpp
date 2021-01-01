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
    int N;
    string s;
    cin >> s;
    N = s.size();
    vector<pair<char, int>> ran;
    rep(i,N){
        char c = s[i];
        int cnt = 1;
        while(i < N){
            if(s[i] == s[i+1]){
                ++cnt;
                ++i;
            }else break;
        }
        ran.push_back(make_pair(c, cnt));
    }
    //for(auto x:ran){
    //    printf("%c x %d\n", x.first, x.second);
    //}
    int ans = 0;
    for(int i = 0; i + 2 < ran.size(); ++i){
        if(ran[i].first == 'J' && ran[i+1].first == 'O' && ran[i+2].first == 'I' && ran[i+1].second <= ran[i].second && ran[i+1].second <= ran[i+2].second){
            ans = max(ans, ran[i+1].second);
        }
    }
    cout << ans << endl;
    return 0;
}
