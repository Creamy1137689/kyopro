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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N; cin >> N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	vector<int> act(N, 0);
	//1->buy 2->sell
	act[0] = 1;
	int lt_act = 0;
	for(int i = 1; i < N; ++i){
		if(A[i] < A[i-1]){
			act[i-1] = 2;
			act[i] = 1;
			lt_act = i;
		}
	}
	// cout <<lt_act << endl;
	if(A[lt_act] < A[N-1]){
		act[N-1] = 2;
	}else{
		act[lt_act] = 0;
	}
	// show(act);
	ll money = 1000;
	ll kabu = 0;
	rep(i,N){
		if(act[i] == 1){
			kabu += money/A[i];
			money %= A[i];
		}else if(act[i] == 2){
			money += kabu*A[i];
			kabu = 0;
		}
		// printf("[money:kabu] -> [%lld, %lld]\n", money, kabu);
	}
	cout << money << endl;
	return 0;
}