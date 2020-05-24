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
#define REP(i,n) for(int i = 1; i<n; ++i)
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

int H,W,N;
char m[1008][1008];
int dist[1008][1008];
int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

int main(){
    cin>>H>>W>>N;
    queue <ip> Q;
    ip di[10];
    REP(i,H+1)REP(j,W+1){
        char tmp;
        cin>>tmp; m[i][j] = tmp;
        dist[i][j] = inf;
        if(tmp=='S')Q.push(make_pair(i,j));
        if('1'<=tmp&&tmp<='9')di[tmp-'0'] = make_pair(i,j);
    }
    
    dist[Q.front().first][Q.front().second] = 0;
    REP(c,N+1){
        while(!Q.empty()){
            int y = Q.front().first, x = Q.front().second;
            Q.pop();
            rep(i,4){
                int cy = y+d4y[i], cx = x+d4x[i];
                if(m[cy][cx] != 'X' && dist[cy][cx] == inf){
                    Q.push(make_pair(cy,cx));
                    dist[cy][cx] = dist[y][x] + 1;
                }
            }
        }
        REP(i,H+1)REP(j,W+1){
            if(i == di[c].first && j == di[c].second)continue;
            dist[i][j] = inf;
        }
        Q.push(make_pair(di[c].first,di[c].second));
    }
    cout<<dist[di[N].first][di[N].second]<<endl;
}
