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

int ddx[4] = {0,1,0,-1};
int ddy[4] = {1,0,-1,0};

const int H = 4020, W = 4020;
short nap[H][W] = {};

void dfs(int i, int j){
    stack<P> st;
    nap[i][j] = 1;
    st.emplace(i, j);
    while(!st.empty()){
        int y = st.top().first, x = st.top().second;
        st.pop();
        rep(k,4){
            int dy = y + ddy[k], dx = x + ddx[k];
            if(dy < 0 || dx < 0 || dx >= W || dy >= H)continue;
            if(nap[dy][dx] == 0){
                nap[dy][dx] = 1;
                st.emplace(dy, dx);
            }
        }
    }
}

void cl(vector<int> &arg, int l){
    arg.push_back(0); arg.push_back(l);
    sort(all(arg));
    arg.erase(unique(all(arg)), arg.end());
    arg.erase(remove(all(arg), -1), arg.end());
    arg.erase(remove(all(arg), l+1), arg.end());
}

int main(){
    int h, w, n, x1, y1, x2, y2;
    cin >> w >> h >> n;
    vector<int> we, he;
    vector<P> top(n);
    vector<P> bottom(n);
    rep(i,n){
        cin >> x1 >> y1 >> x2 >> y2;
        we.push_back(x1); we.push_back(x1+1); //we.push_back(x1-1);
        we.push_back(x2); we.push_back(x2+1); //we.push_back(x2-1);
        he.push_back(y1); he.push_back(y1+1); //he.push_back(y1-1);
        he.push_back(y2); he.push_back(y2+1); //he.push_back(y2-1);
        top[i] = make_pair(x1, y1);
        bottom[i] = make_pair(x2, y2);
    }
    cl(we, w); cl(he, h);

    //printf("This is %d * %d grid.\n", (int)he.size(), (int)we.size());
    rep(i,n){
        x1 = (int)(lower_bound(all(we), top[i].first) - we.begin());
        x2 = (int)(lower_bound(all(we), bottom[i].first) - we.begin());
        y1 = (int)(lower_bound(all(he), top[i].second) - he.begin());
        y2 = (int)(lower_bound(all(he), bottom[i].second) - he.begin());
        //printf("[%d, %d] -> [%d, %d]\n", y1, x1, y2, x2);
        //if(!(0 <= x1 && x1 < W) || !(0 <= x2 && x2 < W) || !(0 <= y1 && y1 < H) || !(0 <= y2 && y2 < H))return 0;
        nap[y1][x1]++;
        nap[y2][x2]++;
        nap[y2][x1]--;
        nap[y1][x2]--;
        //if(i == 0){
        //    cout << endl;
        //    printf("[%d, %d] -> [%d, %d]\n", y1, x1, y2, x2);
        //    rep(k,he.size()){rep(l,we.size())cout << nap[k][l] << ' ';cout << endl;}
        //    cout << endl;
        //}
    }
    rep(i,he.size())rep(j,we.size())nap[i][j+1] += nap[i][j];
    rep(j,we.size())rep(i,he.size())nap[i+1][j] += nap[i][j];
    rep(i,he.size())nap[i][we.size()-1] = 1;
    rep(j,we.size())nap[he.size()-1][j] = 1;
    //rep(i,nap.size()){rep(j,nap[i].size())cout << nap[i][j] << ' ';cout << endl;}
    int ans = 0;
    rep(i,he.size())rep(j,we.size()){
        if(nap[i][j] == 0){
            ++ans;
            dfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
