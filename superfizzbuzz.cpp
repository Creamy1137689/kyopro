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

int main(){
    int n; cin>>n;
    REP(i,n){
        string s = "";
        if(i%2==0)s.push_back('a');
        if(i%3==0)s.push_back('b');
        if(i%4==0)s.push_back('c');
        if(i%5==0)s.push_back('d');
        if(i%6==0)s.push_back('e');
        if(s.size() == 0)cout<<i<<endl;
        else cout<<s<<endl; 
    }
}
