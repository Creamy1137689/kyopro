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
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int x; cin>>x;
    int count = x/100;

    if(100*count<=x&&x<=105*count)cout<<1<<endl;
    else cout<<0<<endl;
    /*
    int rest = x%100;
    int coin = 0;
    int n_rest = rest;
    
    for(int a=0; a*5<=rest&&a<=count; ++a){
        n_rest = rest-a*5;
        coin = a;
        for(int b=0; b*4<=n_rest&&coin+b<=count; ++b){
            n_rest -= b*4;
            coin += b;
            for(int c=0; c*3<=n_rest&&coin+c<=count; ++c){
                n_rest -= c*3;
                coin += c;
                for(int d=0; d*2<=n_rest&&coin+d<=count; ++d){
                    n_rest -= d*2;
                    coin += d;
                    for(int e=0; e<=n_rest&&coin+e<=count; ++e){
                        n_rest -= e;
                        coin += e;
                        if(n_rest == 0){cout<<1<<endl; return 0;}
                    }
                }
            }
        }
    }
    */
    //cout<<0<<endl; return 0;
}
