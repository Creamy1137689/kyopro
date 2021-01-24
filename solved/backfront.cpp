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
	vector<int> P(N);
	vector<int> pos(N+1);
	rep(i,N){
		cin >> P[i];
		pos[P[i]] = i;
	}
	vector<int> dp(N+1);
	rep(i,N){
		dp[P[i]] = 1;
		if(P[i] == 1)continue;
		if(i > pos[P[i]-1]){
			dp[P[i]] = dp[P[i]-1] + 1;
		}
	}
	int nax = 0;
	rep(i,N+1)nax = max(nax, dp[i]);
	cout << N - nax << endl;
}

//int main(){
//	int N; 
//	cin >> N;
//	vector<int> P(N);
//	vector<int> pos(N);
//	rep(i,N){
//		cin >> P[i];
//		--P[i];
//		pos[P[i]] = i;
//	}
//	int ans = 0;
//	int add_front = -1;
//	int add_back = N;
//	int lst = N/2-1;
//	int rst = N/2;   	if(N % 2 == 1)rst ++;
//	for( ; lst >= 0; lst --){
//		if(pos[lst] > pos[lst + 1]){
//			pos[lst] = add_front--;
//			++ans;
//		}
//	}
//	for( ; rst < N; ++rst){
//		if(pos[rst] < pos[rst - 1]){
//			pos[rst] = add_back ++;
//			++ans;
//		}
//	}
//	cout << ans << endl;
//}

//int main(){
//	int N; 
//	cin >> N;
//	vector<int> P(N);
//	rep(i,N)cin >> P[i];
//	set<int> fward, bward;
//	REP(i,N){
//		fward.insert(i);
//		bward.insert(i);
//	}
//	int f_ans = 0, b_ans = 0;
//	vector<int> fremain;
//	vector<int> bremain;
//	int min_forward = inf, max_backward = -inf;
//	//forward
//	{
//		rep(i,N){
//			auto itr = fward.begin();
//			if(*itr < P[i]){
//				min_forward = min(min_forward, P[i]);
//				++f_ans;
//			}else{
//				fremain.push_back(P[i]);
//			}
//			fward.erase(P[i]);
//		}
//		for(auto x:fremain){
//			if(x > min_forward) ++f_ans;
//		}
//	}
//	//backward
//	{
//		for(int i = N-1; i >= 0; --i){
//			auto itr = bward.rbegin();
//			if(*itr > P[i]){
//				max_backward = max(max_backward, P[i]);
//				++b_ans;
//			}else{
//				bremain.push_back(P[i]);
//			}
//			bward.erase(P[i]);
//		}
//		for(auto x:bremain){
//			if(x < max_backward) ++b_ans;
//		}
//	}
//	cout << min(f_ans, b_ans) << endl;
//	return 0;
//}
