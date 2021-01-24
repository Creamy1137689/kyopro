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
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i,N)cin >> a[i];
    rep(i,N)cin >> b[i];
    ll suma = 0, sumb = 0;
    rep(i,N)suma += a[i];
    vector<pair<ll, int>> even(N/2), odd(N/2);
    rep(i,N/2){
        even[i].first = b[i*2] - a[i*2];
        odd[i].first = b[i*2+1] - a[i*2+1];
        even[i].second = i*2;
        odd[i].second = i*2 + 1;
    }
    sort(all(even), greater<pair<ll, int>>()); sort(all(odd), greater<pair<ll,int>>());
    ll ans = suma + sumb;
    rep(i,N/2){
        int even_ind = even[i].second, odd_ind = odd[i].second;
        suma -= a[even_ind] + a[odd_ind];
        sumb += b[even_ind] + b[odd_ind];
        ans = max(ans, suma + sumb);
    }
    cout << ans << endl;
    return 0;
}
