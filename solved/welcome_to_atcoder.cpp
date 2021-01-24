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
typedef long long ll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n,m; cin>>n>>m;
    vector<int> p(m);
    vector<string> s(m);
    rep(i,m)cin>>p[i]>>s[i];

    int ac_ans = 0, wa_ans = 0;
    pair<int,int> submit(0,0);
    vector<pair<int,int>> submits(n,submit);
    //for(auto x:submits)cout<< x.first<<' '<<x.second<<endl;

    rep(i,m){
        if(s[i] == "AC"){
            if(submits[p[i]-1].second == 0){ac_ans++; wa_ans += submits[p[i]-1].first; submits[p[i]-1].second = 1;}
        }else{
            submits[p[i]-1].first++;
        }
        //cout<<"--------------"<<endl;
        //for(auto x:submits)cout<< x.first<<' '<<x.second<<endl;
        //cout<<"--------------"<<endl;
    }

    cout<<ac_ans<<' '<<wa_ans<<endl;return 0;
}
