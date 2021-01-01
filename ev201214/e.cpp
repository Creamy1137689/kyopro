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
#define show(obj) {for(auto x:obj)cout<<x; cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

char inv(char c){
    return (c == 'W' ? 'S' : 'W');
}

char nt(char n, char b, char c){
    if(n == 'S'){
        if(c == 'o')return b;
        else return inv(b);
    }else{
        if(c == 'x')return b;
        else return inv(b);
    }
}

int main(){
    int N;
    string ss;
    cin >> N >> ss;
    vector<char> ans(N);
    rep(f,2){
        rep(s,2){
            ans[0] = (f == 0 ? 'W' : 'S');
            ans[1] = (s == 0 ? 'W' : 'S');
            for(int i = 2; i < N; ++i){
                ans[i] = nt(ans[i-1], ans[i-2], ss[i-1]);
            }
            if(ans[0] == nt(ans[N-1], ans[N-2], ss[N-1]) && ans[1] == nt(ans[0], ans[N-1], ss[0])){
                show(ans);
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
