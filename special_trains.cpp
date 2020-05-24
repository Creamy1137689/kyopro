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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

struct st{
	int c;
	int s;
	int f;
};

int main(){
	int N; cin>>N;
	vector<st> train(N-1);
	rep(i,N-1)cin>>train[i].c>>train[i].s>>train[i].f;
	rep(i,N-1){
		int e_ans = 0;
		for(int j = i; j<N-1; ++j){
			e_ans = max(train[j].s, (int)ceil((double)e_ans/train[j].f)*train[j].f);
			e_ans += train[j].c;
		}
		cout<<e_ans<<endl;
	}
	cout<<0<<endl;
	return 0;
}