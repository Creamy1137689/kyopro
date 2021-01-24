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
	int N; cin >> N;
	string s; cin >> s;
	int r_cnt = 0, w_cnt = 0;
	rep(i,N){
		if(s[i] == 'R')++r_cnt;
		else ++w_cnt;
	}
	int r_no_move = 0, w_no_move = 0;
	rep(i,r_cnt){
		if(s[i] == 'R')++r_no_move;
	}
	rep(i,w_cnt){
		if(s[N-1-i] == 'W')++w_no_move;
	}
	cout << min(r_cnt - r_no_move, w_cnt - w_no_move) << endl;
	return 0;
}
