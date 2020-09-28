#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    string s;
    cin >> s;
    for(int bit = 0; bit < (1<<4); ++bit){
        bool exi[4] = {false};
        rep(i,4){
            if(bit & (1 << i))exi[i] = true;
        }
        string now;
        if(exi[0])now += 'A';
        now += "KIH";
        if(exi[1])now += 'A';
        now += "B";
        if(exi[2])now += 'A';
        now += "R";
        if(exi[3])now += 'A';
        if(s == now){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
