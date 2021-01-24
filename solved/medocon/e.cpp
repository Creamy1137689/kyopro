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

struct d{
	int dis;
	int a;
	int b;
};

bool compare(d a, d b) {
	return a.dis > b.dis;
}



int main(){
	int N; cin>>N;
	vector<P> dot(N);
	rep(i,N)cin>>dot[i].first;
	rep(i,N)cin>>dot[i].second;
	vector<d> alldis;
	rep(i,N){
		for(int j = i+1; j < N; ++j){
			int t = abs(dot[i].first - dot[j].first) + abs(dot[i].second - dot[j].second);
			d st = {t, i, j};
			alldis.push_back(st);
		}
	}
	sort(all(alldis), compare);
	int ans = inf;
	rep(i,N){
		set<int> al;
		al.insert(i);
		int e_ans = 0;
		int cnt = 1;
		for(auto x: alldis){
			if(al.count(x.a) == 0 && al.count(x.b) ==1 ){
				e_ans += x.dis * cnt;
				++cnt;
				al.insert(x.a);
			}else if(al.count(x.a) == 1 && al.count(x.b) == 0){
				e_ans += x.dis*cnt;
				al.insert(x.b);
				++cnt;
			}
		}
		ans = min(ans, e_ans);
	}
	cout<<200000000-ans<<endl;
	return 0;
}