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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

vector<int> manachar(const string &s){
    vector<int> r(s.size(), 0);
    int i = 0, j = 0;
    while(i < s.size()){
        while(i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) ++j;
        r[i] = j;
        int k = 1;
        while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], ++k;
        i += k; j-= k;
    }
    return r;
}
