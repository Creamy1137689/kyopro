#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
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

int M_H = 550, M_W = 550;
vector<vector<char>> m(M_H,vector<char> (M_W));
vector<vector<bool>> ans(M_H,vector<bool>(M_W,false));
int h,w;

void bfs(int y, int x){
    if(y<0||y>=h||x<0||x>=w || m[y][x] == '#')return;
    if(ans[y][x])return;
    ans[y][x] = true;
    bfs(y-1,x); bfs(y+1,x); bfs(y,x-1); bfs(y,x+1);
}

int main(){
    cin>>h>>w;
    ip s,g;
    rep(i,h)rep(j,w){
        cin>>m[i][j];
        if(m[i][j] == 's'){s.first = i;s.second = j;}
        if(m[i][j] == 'g'){g.first = i; g.second = j;}
    }
    bfs(s.first,s.second);
    cout<<((ans[g.first][g.second])?"Yes":"No")<<endl; return 0;
}