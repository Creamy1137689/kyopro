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
#define REP(i,n) for(int i = 1; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    int n;cin>>n;
    vector <int> p(n); rep(i,n)cin>>p[i];
    int changed = 0;
    rep(i,n){
        if(p[i] != i+1)changed++;
    }
    cout<<((changed <= 2)?"YES":"NO")<<endl;return 0;
}
