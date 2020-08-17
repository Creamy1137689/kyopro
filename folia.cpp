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
	ll N;
	cin >> N;
	++N;
	vector<ll> node(N);
	rep(i,N)cin >> node[i];

	vector<ll> nax(N, inf);
	vector<ll> nin(N, inf);
	nax[N-1] = node[N-1];
	nin[N-1] = node[N-1];
	for(int i = N-2; i >= 0; --i){
		nin[i] = (nin[i+1]/2 + (nin[i+1] % 2 != 0) + node[i]);
		nax[i] = (nax[i+1] + node[i]);
	}
	if(!(nin[0] <= 1 && 1 <= nax[0])){
		cout << -1 << endl;
		return 0;
	}

	ll ans = 1;
	vector<ll> det_node(N+1);
	det_node[0] = 1;
	REP(i,N-1){
		det_node[i] = min(nax[i], (det_node[i-1]-node[i-1])*2);
		ans += det_node[i];
	}
	cout << ans << endl;
}


//
//int main(){
//	int N; cin>>N;
//	++N;
//	vector<int> node(N);
//	rep(i,N)cin>>node[i];
//
//	//possible or impossible
//	{
//		int can = 1;
//		int i = 0;
//		while(i <= N && can <100100100){
//			if(node[i] > can){
//				cout << -1 << endl;
//				return 0;
//			}
//			can -= node[i];
//			can *= 2;
//			++i;
//		}
//		if(node[N] == 0){cout << -1 << endl; return 0;}
//	}
//
//	//ans
//	ll ans = N+1;
//	vector<int> rest(N+1);
//	return 0;
//}
