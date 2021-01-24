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
	int H, W, N, sy, sx;
	string T, A;
	cin >> H >> W >> N >> sy >> sx >> T >> A;
	--sy; --sx;
	bool win_aoki = true;
	//holizon
	int l = 0, r = W-1;
	for(int i = N-1; i >= 0; --i){
		if(A[i] == 'L'){
			r = min(W-1, r + 1);
		}else if(A[i] == 'R'){
			l = max(0, l - 1);
		}
		if(T[i] == 'L'){
			++l;
		}else if(T[i] == 'R'){
			--r;
		}
		if(l > r){
			win_aoki = false;
			break;
		}
	}
	if(!(l <= sx && sx <= r))win_aoki = false;
	l = 0; r = H - 1;
	//vertex
	for(int i = N-1; i >= 0; --i){
		if(A[i] == 'U'){
			r = min(H-1, r + 1);
		}else if(A[i] == 'D'){
			l = max(0, l - 1);
		}
		if(T[i] == 'U'){
			++l;
		}else if(T[i] == 'D'){
			--r;
		}
		if(l > r){
			win_aoki = false;
			break;
		}
	}
	if(!(l <= sy && sy <= r))win_aoki = false;
	cout << ((win_aoki) ? "YES" : "NO") << endl;
	return 0;
}
