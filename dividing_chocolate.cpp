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
	int H,W,K; cin>>H>>W>>K;
	vector<vector<char>> choco(H, vector<char> (W));
	rep(i,H)rep(j,W)cin>>choco[i][j];
	int ans = inf;
	for(int bit = 0; bit < (1<<(H-1)); ++bit){
		vector<int> uni(H);
		int div_row = 0;
		int e_ans = 0;
		rep(i,H-1){
			uni[i] = div_row;
			if(bit & (1<<i)){
				++div_row;
			}
		}
		uni[H-1] = div_row;

		// cout<<line<<endl;
		// printf("[%d] ... ", bit);
		// show(uni);
		vector<int> bk_cnt(div_row+1,0);
		rep(j,W){
			vector<int> t(div_row+1,0);
			rep(i,H){
				if(choco[i][j] == '1'){
					t[uni[i]]++;
				}
			}
			bool go = true;
			rep(i,div_row+1){
				if(t[i] > K)e_ans += 100000;
				if(bk_cnt[i] + t[i] > K){
					go = false;
					break;
				}
			}
			if(go){
				rep(i,div_row+1)bk_cnt[i] += t[i];
			}else{
				e_ans++;
				rep(i,div_row+1)bk_cnt[i] = t[i];
			}
			// show(bk_cnt);
		}
		// printf("this term's ans is %d\n", e_ans+div_row);
		// cout<<line<<endl;
		ans = min(ans, e_ans+div_row);
	}
	cout<<ans<<endl;
	return 0;
}