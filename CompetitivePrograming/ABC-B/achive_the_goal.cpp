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
    int n,k,m;cin>>n>>k>>m;
    int sum = 0; rep(i,n-1){int tmp;cin>>tmp;sum+=tmp;}
    int ans = m*n-sum;
    cout<<((ans<=k)?max(0,ans):-1)<<endl;return 0;
}
