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
	vector<int> color(2*N);
	rep(i,N){
		cin >> color[i];
		color[i + N] = color[i];
	}
	int max_len = 0;
	for(int i = 0; i < N; ++i){
		int seq = 1;
		while(color[i] == color[i+1]){
			++seq;
			++i;
		}
		max_len = max(seq, max_len);
	}	
	if(max_len >= N)cout << -1 << endl;
	else cout << (max_len - 1) / 2 + 1 << endl;
	return 0;
}
