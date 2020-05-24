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
    int n;string s; cin>>n>>s;
    int ans = 0;
    rep(i,n-2){
        if(s[i] == 'A')if(s[i+1]=='B')if(s[i+2]=='C')++ans;
    }
    cout<<ans<<endl;return 0;
}
