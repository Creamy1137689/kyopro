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
	string s,t;
	cin>>s>>t;
	ll siz = s.size();

	//possible impossible
	set<char> check;
	rep(i,siz)check.insert(s[i]);
	rep(i,t.size()){
		if(check.count(t[i]) == 0){
			cout<<-1<<endl;
			return 0;
		}
	}

	//solve
	string comp = s+s;
	ll ans = 0;
	vector<vector<int>> chcnt(26, vector<int> ());
	rep(i,comp.size()){
		chcnt[comp[i] - 'a'].push_back(i+1);
	}
	rep(i,t.size()){
		int ch = t[i] - 'a';
		int base = ans % siz;
		auto itr = upper_bound(all(chcnt[ch]), base);
		ans += *itr-base;
	}
	cout<<ans<<endl;
}

// vector<vector<ll>> chcnt(26, vector<ll> ());
// vector<ll> naxs(26);

// bool isOK(ll chnum, ll k, ll index, ll key){
//     if(chcnt[chnum][index] + k > key) return true;
//     else return false;
// }

// ll binary_search(ll chnum, ll k, ll nax, ll key){
//     ll ng = -1;
//     ll ok =nax;
//     while(abs(ok-ng) > 1){
//         ll mid = (ok + ng)/2;
//         if(isOK(chnum, k, mid, key))ok = mid;
//         else ng = mid;
//     }
//     return ok;
// }

// int main(){
// 	string s,t; cin>>s>>t;
// 	set<char> cnt;
// 	rep(i,s.size())cnt.insert(s[i]);
// 	bool ok = true;
// 	rep(i,t.size())if(cnt.count(t[i]) == 0)ok = false;
// 	if(!ok){cout<<-1<<endl; return 0;}

// 	rep(i,s.size()){
// 		ll ind = s[i] - 'a';
// 		chcnt[ind].push_back(i+1);
// 		naxs[ind] = i+1;
// 	}
// 	ll ans = 0;
// 	ll bfans = -1;
// 	rep(i,t.size()){
// 		ll ind = t[i] - 'a';
// 		ll tmp = max(ans-naxs[ind], 0LL);
// 		ll k = (ll)(tmp/s.size() + (tmp%s.size() != 0)) * (ll)s.size();
// 		// ll k = ceil(max(ans-naxs[ind], 0LL)/(double)s.size()) * (ll)s.size();
// 		ll e_ans = binary_search(ind, k, chcnt[ind].size(), ans);
// 		ans = k+chcnt[ind][e_ans];
// 		if(ans == bfans){
// 			k+=(ll)s.size();
// 			e_ans = binary_search(ind, k, chcnt[ind].size(), ans);
// 			ans = k+chcnt[ind][e_ans];
// 		}
// 		bfans = ans;
// 		// printf("%c is %lld [k = %lld, e_ans = %lld, add = %lld]\n", 
// 		// 	(char)('a'+ind), ans, k, e_ans, chcnt[ind][e_ans]);
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }