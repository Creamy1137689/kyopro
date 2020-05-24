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
    int L_MAX = 2100;
    int n; cin >> n;
    vector<int> array(n,0);
    rep(i,n)cin >> array[i];

    vector <ll> l(L_MAX,0);
    rep(i,n)l[array[i]]++;

    vector <ll> sum(L_MAX+1,0);
    rep(i,L_MAX)sum[i+1] = sum[i] + l[i];
    //for(auto c : l)cout << c << ' ';
    int ans = 0;
    rep(i,n)rep(j,n){
        if(i == j) continue;
        //cout << array[i] << ',' << array[j] << ',' << max(sum[min(array[i] + array[j],L_MAX)] -sum[abs(array[i]-array[j])+1],0) << endl;
      
        int left = abs(array[i] - array[j]) + 1;
        int right = array[i] + array[j];

        int count = sum[right] - sum[left];
        if(left <= array[i] && array[i] < right)--count;
        if(left <= array[j] && array[j] < right)--count;
        ans += max(count,0);
    }
    cout << "------------" << endl;
    cout << ans << endl;
    cout << ans/6 << endl; return 0;
}
