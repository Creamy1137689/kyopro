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
    int n; cin>>n;
    vector <int> h(n); rep(i,n)cin>>h[i];
    vector <int> cost(n,0);
    cost[1] = abs(h[1]-h[0]);
    for(int i = 2; i<n; ++i){
        cost[i] = min(cost[i-1]+abs(h[i]-h[i-1]), cost[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<cost[n-1]<<endl;return 0;
}
