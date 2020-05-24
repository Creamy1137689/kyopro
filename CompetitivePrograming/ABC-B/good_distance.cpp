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
    int n,d; cin>>n>>d;
    vector<vector<int>> points(n, vector<int>(d));
    rep(i,n)rep(j,d)cin>>points[i][j];
    
    int ans = 0;
    rep(i,n){
        for(int j = i+1; j<n; ++j){
            double sum = 0.0;
            rep(dim,d){
                sum += pow(points[i][dim]-points[j][dim],2);
            }
            if(sqrt(sum) == (int)sqrt(sum))++ans;
        }
    }
    cout<<ans<<endl;return 0;
}
