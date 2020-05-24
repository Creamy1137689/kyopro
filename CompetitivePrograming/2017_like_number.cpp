#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;

typedef long long ll;

int main(){
    const int MAX = 100100;
    vector <int> num(MAX,1);
    vector <int> l_num(MAX+1,0);
    num[0] = 0; num[1] = 0;
    for(int i = 2; i<=sqrt(MAX); ++i){
        if(num[i]){
            for(int j = 2; i*j<=MAX; ++j) num[i*j] = 0;
        }
    }
    for(int i = 0; i<MAX+1; ++i) l_num[i+1] = l_num[i] + num[(num[i] ? (i+1)/2 : 0)];
    int q; cin >> q;
    int s[q], e[q]; for(int i = 0; i<q; ++i)cin >> s[i] >> e[i] ;
    for(int i = 0; i<q; ++i){
        int ans = 0;
        ans += l_num[e[i]+1] - l_num[s[i]];
        cout << ans << endl;
    }
    return 0;
}