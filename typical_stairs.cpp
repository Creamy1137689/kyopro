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
    int n,m;cin>>n>>m;
    set<int> a;rep(i,m){int tmp; cin>>tmp; a.insert(tmp);}
    vector<int> stairs(n+1,0);
    stairs[0] = 1; if(a.count(1) == 0)stairs[1] = 1;
    for(int i = 2; i<=n; i++){
        if(a.count(i)==0){
            stairs[i] = (stairs[i-1]+stairs[i-2])%MOD;
        }
    }
    cout<<stairs[n]<<endl;return 0;
}
