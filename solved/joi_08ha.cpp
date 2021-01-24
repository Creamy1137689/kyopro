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
    vector<stack<int>> stones(2, stack<int>());
    stones[a[0]].push(0);
    for(int i = 1; i < N; ++i){
        if((i + 1) % 2 == 0){
            if(a[i] != a[i-1]){
                if(!stones[(a[i] == 0)].empty())stones[a[i] == 0].pop();
            }
            if(!stones[a[i]].empty())stones[a[i]].pop();
            stones[a[i]].push(i);
        }else{
            if(a[i] == a[i-1]){
                stones[a[i]].pop();
            }
            stones[a[i]].push(i);
        }
    }
    vector<int> ans(N);
    int s = 0;
    for(int i = N-1; i >= 0; --i){
        if(!stones[0].empty()){
            if(stones[0].top() == i){s = 0; stones[0].pop();}
        }
        if(!stones[1].empty()){
            if(stones[1].top() == i){s = 1; stones[1].pop();}
        }
        ans[i] = s;
    }
    int res = 0;
    rep(i,N)if(ans[i] == 0)++res;
    cout << res << endl;
    return 0;
}
