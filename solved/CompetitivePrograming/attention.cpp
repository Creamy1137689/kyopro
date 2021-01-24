#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; string s; cin >> n >> s;
    vector<int> w(n+1,0), e(n+1,0);
    for(int i = 0; i<n; ++i){
        w[i+1] = w[i] + (s[i] == 'W');
        e[i+1] = e[i] + (s[i] == 'E');
    }
    int ans = e[n] - e[1];
    for(int i = 1; i<n; ++i){
        int tmp_ans = w[i] + e[n] - e[i+1];
        if(tmp_ans < ans)ans = tmp_ans;
    }
    cout << ans << endl; return 0;
}