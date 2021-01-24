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
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

char in[510][510];
int ans[510][510];

int main(){
    int H,W;cin>>H>>W;
    ip g;
    deque<ip> Q;
    REP(i,H)REP(j,W){
        cin>>in[i][j];
        ans[i][j] = inf;
        if(in[i][j] == 's'){Q.push_front(make_pair(i,j));ans[i][j] = 0;}
        if(in[i][j] == 'g'){g.first = i;g.second = j;}
    }
    while(!Q.empty()){
        int y = Q.front().first, x = Q.front().second;
        Q.pop_front();
        rep(i,4){
            int dy = y+d4y[i] , dx = x+d4x[i];
            if(ans[dy][dx] == inf && in[dy][dx] != '#'){
                ans[dy][dx] = ans[y][x];
                Q.push_front(make_pair(dy,dx));
            }
            
            if(ans[dy][dx] == inf && in[dy][dx] == '#'){
                ans[dy][dx] = ans[y][x]+1;
                Q.push_back(make_pair(dy,dx));
            }
        }
    }
    if(ans[g.first][g.second] <= 2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl; return 0;
}
