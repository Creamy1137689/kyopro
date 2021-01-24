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

char win(char a, char b){
    if(a == b)return a;
    if(a == 'R' && b == 'S')return a;
    if(a == 'P' && b == 'R')return a;
    if(a == 'S' && b == 'P')return a;
    return b;
}

int main(){
    int N, K;
    string s;
    cin >> N >> K >> s;
    while(K-- > 0){
        if(s.size() % 2 == 1)s += s;
        string t;
        rep(i,s.size()/2){
            t += win(s[i*2], s[i*2+1]);
        }
        s = t;
    }
    cout << s[0] << endl;
    return 0;
}
