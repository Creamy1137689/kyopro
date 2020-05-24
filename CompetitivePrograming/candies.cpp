#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int map[2][n];
    for(int i = 0; i<2; ++i)for(int j = 0; j<n; ++j)cin >> map[i][j];
    int ans = 0;
    for(int i = 1; i<=n; ++i){
        int pos = 1, tmp_ans = map[0][0];
        while(pos<i){
            tmp_ans += map[0][pos];
            ++pos;
        }
        --pos;
        while(pos<n){
            tmp_ans += map[1][pos];
            ++pos;
        }
        cout << tmp_ans << endl;
        if(ans < tmp_ans)ans = tmp_ans;
    }
    cout << ans << endl;
}