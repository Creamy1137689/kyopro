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
    int n;cin>>n;
    double ans = 0.0;
    rep(i,n){
        double tmp; cin>>tmp;
        ans += 1.0/tmp;
    }
    ans = 1.0/ans;
    cout<<fixed<<setprecision(10)<< ans <<endl;return 0;
}
