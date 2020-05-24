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

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};
int cnt = 0;
char m[10][10];
int ans[10][10] = {0};
int full[10][10] = {0};

int dfs(int y,int x){
    rep(i,4){
        int dy = y+d4y[i], dx = x+d4x[i];
        if(0<=dx&&dx<10&&0<=dy&&dy<10){
            if(m[dy][dx] == 'x')ans[dy][dx]++;
            else { m[dy][dx] = 'x'; dfs(dy,dx);}
        }
    }
    return 0;
}

int main(){
    rep(i,10)rep(j,10)cin>>m[i][j];
    rep(i,10)rep(j,10){
        if(m[i][j] == 'o'){
            rep(k,10)rep(l,10)ans[k][l] = 0; 
            dfs(i,j); ++cnt;
            rep(k,10)rep(l,10)if(ans[k][l]>0)full[k][l]++;
        }
    }    
    rep(i,10)rep(j,10){
        if(full[i][j] == cnt){cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl; return 0;
}
