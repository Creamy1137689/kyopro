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
    string s;
    cin >> N >> s;
    stack<char> Q;
    int match = 0;
    rep(i,N){
        if(s[i] == 'x'){
            if(Q.size() < 2){Q.push('A'); continue;}
            char b1 = Q.top(); Q.pop();
            char b2 = Q.top(); Q.pop();
            if(b2 == 'f' && b1 == 'o')match += 3;
            else{
                Q.push('A'); Q.push('A');
            }
        }else{
            Q.push(s[i]);
        }
    }
    cout << N - match << endl;
}

//int main(){
//    int N;
//    string s;
//    cin >> N >> s;
//    char ch[4] = {'f', 'o', 'x', 'A'};
//    int cnt[4] = {};
//    int match = 0;
//    rep(i,N){
//        bool ok = false;
//        int pos = 3;
//        rep(j,3){
//            if(s[i] == ch[j]){
//                pos = j;
//                ok = true;
//                break;
//            }
//        }
//        ++cnt[pos];
//        rep(j,3){
//            if(abs(cnt[j]- cnt[j+1]) > 1)ok = false;
//        }
//        if(cnt[3] > 0)ok = false;
//        if(!ok){
//            rep(j,4)cnt[j] = 0;
//        }
//        if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
//            --cnt[0]; --cnt[1]; --cnt[2];
//            match += 3;
//        }
//    }
//    cout << N - match << endl;
//    return 0;
//}
