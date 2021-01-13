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

int main(){
    int p;
    cin >> p;
    vector<int> fib(8000000);
    fib[0] = 1; fib[1] = 1;
    set<P> al;
    al.insert(make_pair(1, 1));
    int i = 2;
    while(true){
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= p;
        if(fib[i] == 0){
            cout << i + 1 << endl;
            return 0;
        }
        if(al.count(make_pair(fib[i-1], fib[i])) == 0){
            al.insert(make_pair(fib[i-1], fib[i]));
        }else{
            cout << -1 << endl;
            return 0;
        }
        ++i;
    }
    return 0;
}
