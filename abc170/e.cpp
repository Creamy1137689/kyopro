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
	int N,Q; cin>>N>>Q;
	vector<P> child(N);
	rep(i,N)cin >> child[i].first >> child[i].second;

	//rate, child_num
	vector<set<P>> kind(200000, set<P>());
	rep(i,N){
		--child[i].second;
		int pos = child[i].second;
		kind[pos].insert(make_pair(child[i].first, i));
	}

	//key = rate, value = kind_num
	set<P> ans;
	rep(i,200000){
		if(kind[i].empty())continue;
		P t = *kind[i].rbegin();
		ans.insert(make_pair(t.first, i));
	}

	int child_num, new_kind;
	P a;
	rep(i,Q){
		cin>>child_num>>new_kind;
		--child_num; --new_kind;
		int rate = child[child_num].first;
		int bf_kind = child[child_num].second;

		//ansの削除
		if(!kind[new_kind].empty()){
			a = *kind[new_kind].rbegin();
			P prev_t = make_pair(a.first, new_kind);
			ans.erase(prev_t);
		}
		if(!kind[bf_kind].empty()){
			a = *kind[bf_kind].rbegin();
			P prev_f = make_pair(a.first, bf_kind);
			ans.erase(prev_f);
		}

		//kindの更新
		kind[bf_kind].erase(make_pair(rate, child_num));
		kind[new_kind].insert(make_pair(rate, child_num));

		//ansの追加
		if(!kind[bf_kind].empty()){
			P f = *kind[bf_kind].rbegin();
			ans.insert(make_pair(f.first, bf_kind));
		}
		P t = *kind[new_kind].rbegin();
		ans.insert(make_pair(t.first, new_kind));

		//出力
		P e_ans = *ans.begin();
		cout<<e_ans.first<<endl;
		
		child[child_num].second = new_kind;

		// cout<<line<<endl;
		// rep(i,3){
		// 	for(auto x: kind[i]){
		// 		cout<<x.first<<' ';
		// 	}
		// 	cout<<endl;
		// }
		// for(auto x: ans){
		// 	cout<<x.first<<' '<<x.second<<endl;
		// }
		// cout<<line<<endl;
	}
	return 0;
}