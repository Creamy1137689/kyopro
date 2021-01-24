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

vector<int> ch(vector<int> from, int l, int r){
	if(l > r)swap(l,r);
	vector<int> res;
	rep(i,from.size()){
		if(l <= i && i <= r){
			res.push_back(from[i]);
		}
	}
	return res;
}

int main(){
	int N; cin>>N;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	int ans = -inf;
	rep(tk,N){
		int ao_max = -inf;
		int e_ans;
		rep(ao,N){
			if(tk == ao)continue;
			int tk_cnt = 0, ao_cnt = 0;
			vector<int> k = ch(A, tk, ao);
			rep(i,k.size()){
				if(i%2 == 0){
					tk_cnt += k[i];
				}else{
					ao_cnt += k[i];
				}
			}
			if(ao_cnt > ao_max){
				ao_max = ao_cnt;
				e_ans = tk_cnt;
			}
			// if(tk == 0){
			// 	printf("[ao = %d, tk_cnt, ao_cnt] -> %d, %d\n", ao, tk_cnt, ao_cnt);
			// }
		}
		// printf("[tk = %d] -> %d\n", tk , e_ans); 
		ans = max(ans, e_ans);
	}
	cout<<ans<<endl;
	return 0;
}