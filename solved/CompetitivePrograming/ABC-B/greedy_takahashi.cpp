#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    ll a,b,k;cin>>a>>b>>k;
    ll sum = a+b-k;
    if(sum<=0)cout<< "0 0"<<endl;
    else {cout<<max(0LL,sum-b)<<' '<<min(sum,b)<<endl;}
}
