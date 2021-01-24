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
	int tos[3];
	vector<int> L(N);
	rep(i,3)cin >> tos[i];
	rep(i,N)cin >> L[i];
	sort(tos, tos+3);
	int ans = inf;
	do{
		//cout << line << endl;
		//cout << "tos -> ";
		//show(tos);
		vector<int> tl = L;
		int e_ans = 0;
		rep(i,3){
			int to = tos[i];
			int mp_for_one = inf;
			vector<int> e_tl;
			int rest = tl.size();
			
			//残っている中で最適な組み合わせを探す
			for(int bit = 1; bit < (1 << rest); ++bit){
				vector<int> use;
				vector<int> not_use;
				rep(j, rest){
					if(bit & (1 << j)){
						use.push_back(tl[j]);
					}else{
						not_use.push_back(tl[j]);
					}
				}
				int e_mp = 0;
				int now_long = 0;
				e_mp += 10*(use.size()-1);
				for(auto x:use){
					now_long += x;
				}
				e_mp += abs(to - now_long);

				//最小コストのとき入れ替え
				if(e_mp < mp_for_one){
					e_tl = not_use;
					mp_for_one = e_mp;
				}
			}
			e_ans += mp_for_one;
			tl = e_tl;
			//show(tl);
			//printf("|-->[e_ans = %d]\n", e_ans);
		}
		//cout << e_ans << endl << line << endl;
		ans = min(ans, e_ans);
	}while(next_permutation(tos, tos+3));
	cout << ans << endl;
	return 0;
}
