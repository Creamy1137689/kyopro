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
#define show(obj) {for(auto x:obj)cout<<x<<' ';}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N; cin>>N;
	vector<int> card(2*N, 2);
	rep(i,N){
		int t; cin>>t;
		card[--t] = 1;
	}
	int tar;
	int now = -1;
	rep(i,100*N){
		if(i%2 == 0)tar = 1;
		else tar = 2;
		bool ok = false;
		rep(j,2*N){
			if(card[j] == tar && j>now){
				card[j] = 0;
				now = j;
				ok = true;
				break;
			}
		}
		bool ex = false;
		rep(j,2*N){
			if(card[j] == tar)ex = true;
		}
		// cout<<i<<" | ";
		// show(card);
		// cout<<" | "<<ex<<endl;
		if(!ok)now = -1;
		if(!ex)break;
	}
	int h_ans = 0, t_ans = 0;
	rep(i,2*N){
		if(card[i] == 1) ++h_ans;
		if(card[i] == 2) ++t_ans;
	}
	cout<<t_ans<<endl<<h_ans<<endl;
}

// int main(){
// 	int N; cin>>N;
// 	vector<int> card(2*N, 2);
// 	rep(i,N){
// 		int t; cin>>t;
// 		card[--t] = 1;
// 	}
// 	rep(i,2*N){
// 		cout<<i<<endl;
// 		if(i%2==0){
// 			bool ok = false;
// 			rep(j,2*N){
// 				if(card[j]==1){
// 					card[j] = 0;
// 					ok = true;
// 					break;
// 				}
// 			}
// 			if(!ok)break;
// 		}else{
// 			bool ok = false;
// 			rep(j,2*N){
// 				if(card[j]==2){
// 					card[j] = 0;
// 					ok = true;
// 					break;
// 				}
// 			}
// 			if(!ok)break;
// 		}
// 	}
// 	int h_ans = 0, t_ans = 0;
// 	show(card);
// 	rep(i,2*N){
// 		if(card[i] == 1)t_ans += i+1;
// 		if(card[i] == 2)h_ans += i+1;
// 	}
// 	cout<<t_ans<<endl<<h_ans<<endl;
// 	return 0;
// }