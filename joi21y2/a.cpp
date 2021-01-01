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
    int N, A;
    string s;
    cin >> N >> A >> s;
    ll ans = 0;
    stack<int> bk, fr;
    bk.push(0); fr.push(N+1);
    for(int i = 0; i < A; ++i){
        if(s[i] == '#')bk.push(i +1);
    }
    for(int i = N-1; i+1 > A; --i){
        if(s[i] == '#'){fr.push(i +1);}
    }
    //cout << bk.top() << ' '  << fr.top() << endl ;
    bk.push(A);
    while(bk.size() > 1 || fr.size() > 1){
        int ft = fr.top();
        int bt = bk.top();
       // printf("[%d -> %d]\n", bt, ft);
        ans += abs(ft - bt);
        if(ft != N+1)fr.pop();
        if(bt != 0)bk.pop();
        if(bk.size() == 1 && fr.size() == 1)break;
        bt = bk.top();
        ans += abs(ft-bt);
        if(bk.size() == 2 && fr.size() == 1)break;
    }
    cout << ans << endl;
    return 0;
}
