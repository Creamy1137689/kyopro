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

string solve(int wid, int K){
    if(wid == 1){
        return "J";
    }
    string res;
    if(K <= wid/2){
        res += string(wid/2, 'J');
        res += string(wid/2, 'O');
        return res;
    }else{
        res += string(wid/2, 'I');        
        res += solve(wid/2, K - wid/2);
    }
    return res;
}

int main(){
    int N, K;
    cin >> N >> K;
    int wid = pow(2,N);
    cout << solve(wid, K) << endl;
}

//void fill(int width, int s, vector<vector<char>> &pic){
//    if(width == 1){
//        pic[0][0] = 'J';
//        return ;
//    }
//    int nt_s = s - width/2;
//    for(int i = nt_s+1; i <=s; ++i){
//        for(int j = nt_s+1; j <= s; ++j){
//            pic[i][j] = 'J';
//        }
//    }
//    for(int i = 0; i <= nt_s; ++i){
//        for(int j = nt_s+1; j <= s; ++j){
//            pic[i][j] = 'I';
//        }
//    }
//    for(int i = nt_s+1; i <= s; ++i){
//        for(int j = 0; j <= nt_s; ++j){
//            pic[i][j] = 'O';
//        }
//    }
//    fill(width/2, s - width/2, pic);
//    return ;
//}
//
//int main(){
//    int N, K;
//    cin >> N >> K;
//    int wid = (int)pow(2,N);
//    vector<vector<char>> ans(wid, vector<char>(wid));
//    fill(wid, wid-1, ans);
//    for(int i = wid-1; i >= 0; --i)cout << ans[wid - K][i];
//    cout << endl;
//    return 0;
//}
