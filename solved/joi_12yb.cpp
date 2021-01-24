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
#define show(obj) {for(auto x:obj)cout<<x.first<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N; cin>>N;
	vector<ip> score(N);
	rep(i,N)score[i].second = i;
	rep(i,N*(N-1)/2){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		--a; --b;
		if(c == d){
			++score[a].first;
			++score[b].first;
		}
		if(c > d)score[a].first += 3;
		if(c < d)score[b].first += 3;
	}
	vector<int> pri(N);
	sort(all(score), greater<ip>());
	pri[score[0].second] = 1;
	REP(i,N-1){
		if(score[i].first == score[i-1].first){
			pri[score[i].second] = pri[score[i-1].second];
			continue;
		}
		pri[score[i].second] = i+1;
	}
	rep(i,N)cout<<pri[i]<<endl;
	return 0;
}