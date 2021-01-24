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

int div_cnt(ll k, ll div){
	int res = 0;
	while(k % div == 0){
		++res;
		k /= div;
	}
	return res;
}

ll toll(string s){
	string res;
	bool cnton = false;
	int nd = 9;
	rep(i,s.size()){
		if(s[i] == '.'){
			cnton = true;
		}else{
			if(cnton)--nd;
			res.push_back(s[i]);
		}
	}
	res += string(nd, '0');
	return atoll(res.c_str());
}

int main(){
	int N;
	string a;
	cin >> N;
	vector<P> A(N);
	vector<ll> Ks(N);
	vector<vector<ll>> tmp(64, vector<ll>(22, 0));
	vector<vector<ll>> sum(64, vector<ll>(23, 0));
	rep(i,N){
		cin >> a;
		ll k = toll(a);
		int t = div_cnt(k, 2);
		int f = div_cnt(k, 5);
		A[i] = make_pair(t,f);
		tmp[t][f]++;
		Ks[i] = k;
	}
	rep(i,64){
		rep(j,22){
			sum[i][j+1] = sum[i][j] + tmp[i][j];
		}
	}	
	//rep(i,20){
	//	printf("[%d] ", i);
	//	rep(j,20)cout << sum[i][j] << ' ';
	//	cout << endl;
	//}
	ll ans = 0;
	rep(i,N){
		int need_t = max(18-A[i].first, 0);
		int need_f = max(18-A[i].second, 0);
		if(need_t <= A[i].first && need_f <= A[i].second){
			--ans;
		}
		//int tmp_ans = 0;
		for(int j = need_t; j < 64; ++j){
			ans += sum[j][22] - sum[j][need_f];
			//tmp_ans += sum[j][22] - sum[j][need_f];
		}
		//printf("[%lld]->[need_t = %d, need_f = %d] && tmp_ans = %d && [cnt2:cnt5] = [%d, %d]\n", Ks[i], need_t, need_f, tmp_ans, A[i].first, A[i].second);
	}
	cout << ans/2 << endl;
	return 0;
}
