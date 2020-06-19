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
	int N; cin>>N;
	vector<int> rest(N+1);
	REP(i,N)cin>>rest[i];
	vector<int> sum(N+1,0);
	vector<int> ans(N+1,0);
	int ans_cnt = 0;
	for(int i = N; i > 0; --i){
		if(sum[i]%2 != rest[i]){
			ans[i] = 1;
			++ans_cnt;
			for(int k = 1; k*k <= i; ++k){
				if(i%k == 0){
					++sum[k];
					if(k!= i/k)++sum[i/k];
				}
			}
		}
		// printf("%d has ended\n", i);
		// REP(i,N)cout<<sum[i]<<' ';
		// cout<<endl<<line<<endl;
	}
	cout<<ans_cnt<<endl;
	REP(i,N)if(ans[i] == 1)cout<<i<<endl;
	return 0;
}