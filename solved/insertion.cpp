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

int wall[208][208];
int rate[10][10];

int main(){
    int N; cin>>N;
    string s; cin>>s;
    int a = 0, b = 0;
    int c = 0;
    rep(i,N){
        if(s[i] == '(')a++;
        else b++;
        c = max(c,b-a);
    }
    rep(i,c){
        cout<<'(';
    }
    cout<<s;
    rep(i,a+c-b){
        cout<<')';
    }
}
