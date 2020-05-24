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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

double sqr(long double c) { 
      long double x = c;
      while(true){
          long double x2 = x-(x*x-c)/(x*c);
          if(abs(x2-x)<0.000000001)break;
          x = x2;
      }
      return x;
}

int main(){
	long double a,b,c;
    cin>>a>>b>>c;
    long double to = (c-a-b)/2;
    if(log10(a*b)<2*log10(to))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
