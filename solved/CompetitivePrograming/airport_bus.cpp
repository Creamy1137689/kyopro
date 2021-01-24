#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,c,k; cin >> n >> c >> k;
    int times[n]; for(int i = 0; i<n; ++i) cin >> times[i];
    sort(times, times+n);
    int ans = 0;
    for(int i = 0; i<n;){
        int l_time = times[i] + k;
        for(int j = 1; j<=c && i<n && times[i] <= l_time; ++j){
            ++i;
        }
        ++ans;
    }
    cout << ans << endl; return 0;
}