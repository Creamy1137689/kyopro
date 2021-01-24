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

vector<vector<LP>> memo(4000, vector<LP> (4000));
vector<ll> a(4000);

void init(){
    rep(i,4000)rep(j,4000)memo[i][j] = make_pair(0LL, 0LL);
}

LP dfs(P ran){
    if(memo[ran.first][ran.second] != make_pair(0LL,0LL)){
        return memo[ran.first][ran.second];
    }
    if(ran.second - ran.first == 1)return memo[ran.first][ran.second] = make_pair(a[ran.first],0);
    LP res = make_pair(-1,-1);
    LP front = dfs(make_pair(ran.first+1, ran.second));
    front.second += a[ran.first];
    LP back = dfs(make_pair(ran.first, ran.second-1));
    back.second += a[ran.second-1];
    if(res.second < front.second)res = front;
    if(res.second < back.second) res = back;
    swap(res.first, res.second);
    return memo[ran.first][ran.second] = res;
}

int main(){
    int N;
    cin >> N;
    rep(i,N)cin >> a[i];
    LP ans = dfs(make_pair(0,N));
    cout << ans.first - ans.second << endl;
    return 0;
}
