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
#include <sstream>
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

string ch_st_ll(ll t){
	string res;
	while(t > 0){
		res += (char)('0' + t % 2);
		t /= 2;
	}
	return res;
}

string fill_zero(string s, int len){
	stringstream ss;
	ss << setw(len) << setfill('0') << s;
	return ss.str();
}

int main(){
	ll N, K, input;
	cin >> N >> K;
	string stk = ch_st_ll(K);
	reverse(all(stk));
	int max_len = stk.size();
	vector<string> sta(N);
	rep(i,N){
		cin >> input;
		sta[i] = ch_st_ll(input);
		max_len = max(max_len, (int)sta[i].size());
		reverse(all(sta[i]));
	}
	stk = fill_zero(stk, max_len);
	rep(i,N)sta[i] = fill_zero(sta[i], max_len);

	//dp
	ll dp[50][2] = {0};
	rep(i,max_len)rep(k,2){
		int nd = stk[i] - '0';
		if(i == 0 && k == 1)continue;
		rep(d,2){
			int ni = i+1, nk = k;
			ll add = 0;
			if(k == 0){
				if(d > nd)continue;
				if(d < nd)nk = 1;
			}
			rep(ind, N){
				add += d ^ (sta[ind][i]-'0');
			}
			add *= pow(2, max_len-1-i);
			dp[ni][nk] = max(dp[ni][nk], dp[i][k] + add);
			//cout << line << endl;
			//printf("[digit, k, d, nd] -> [%d, %d, %d, %d]\n", i, k, d, nd);
			//printf("[add, nk] -> [%lld, %d]\n", add, nk);
			//REP(i,max_len)cout << dp[i][0] << ' '; cout << endl;
			//REP(i,max_len)cout << dp[i][1] << ' '; cout << endl;
			//cout << line << endl;
		}
	}
	cout << max(dp[max_len][0], dp[max_len][1]) << endl;
	return 0;
}
