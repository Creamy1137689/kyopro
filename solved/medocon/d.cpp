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

int T,N;
vector<P> dish(100);
int ans = -inf;

void solve(int r_time, int cont){
	rep(i,N){
		if(r_time >= dish[i].first){
			solve(r_time - dish[i].first, cont + dish[i].second);
		}else{
			ans = max(ans, cont);
		}
	}
	return ;
}

int main(){
	cin>>T>>N;
	dish.resize(N);
	rep(i,N)cin>>dish[i].first;
	rep(i,N)cin>>dish[i].second;
	solve(T, 0);
	cout<<ans<<endl;
}

// int main(){
// 	int T,N; cin>>T>>N;
// 	vector<P> dish(N);
// 	rep(i,N)cin>>dish[i].first;
// 	rep(i,N)cin>>dish[i].second;
// 	int ans = -inf;
// 	int perm[8] = {0,1,2,3,4,5,6,7};
// 	do{
// 		int e_ans = 0;
// 		int r_time = T;
// 		rep(i,N){
// 			int p_num = perm[i];
// 			if(r_time < dish[p_num].first)break;
// 			r_time -= dish[p_num].first;
// 			e_ans += dish[p_num].second;
// 		}
// 		cout<<e_ans<<endl;
// 		ans = max(ans, e_ans);
// 	}while(next_permutation(perm, perm+N));
// 	cout<<ans<<endl;
// 	return 0;
// }