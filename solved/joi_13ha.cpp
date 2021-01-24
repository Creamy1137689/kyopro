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
    cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    vector<int> ran;
    ran.push_back(0); ran.push_back(0);
    rep(i,N){
        int cnt = 1;
        while(i < N-1){
            if(a[i] != a[i+1])++cnt, ++i;
            else break;
        }
        ran.push_back(cnt);
    }
    ran.push_back(0); ran.push_back(0);
    int ans = 0;
    for(int i = 0; i < ran.size()-2; ++i){
        ans = max(ans, ran[i] + ran[i+1] + ran[i+2]);
    }
    cout << ans << endl;
    return 0;
}
