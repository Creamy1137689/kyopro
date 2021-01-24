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
	vector<int> isl(N);
	int sum = 0;
	rep(i,N){
		cin>>isl[i];
		sum += isl[i];
	}
	if(sum%N != 0){
		cout<<-1<<endl;
		return 0;
	}
	int ans = 0;
	int now_pep = 0;
	int now_isl = 0;
	rep(i,N){
		now_pep += isl[i];
		++now_isl;
		if(now_pep%now_isl == 0 && now_pep/now_isl == sum/N){
			now_pep = 0;
			now_isl = 0;
			continue;
		}
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}