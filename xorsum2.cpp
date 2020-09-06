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

string atos(int N){
	stringstream res;
	string s;
	while(N > 0){
		s += (char)(N % 2 + '0');
		N /= 2;
	}
	reverse(all(s));
	res << setw(22) << setfill('0') << s;
	return res.str();
}

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	vector<string> S(N);
	rep(i,N)cin >> A[i];
	rep(i,N){
		S[i] = atos(A[i]);
	}
	ll ans = 0;
	int right = 0;
	vector<int> digsum(22,0);
	rep(left, N){
		while(right < N){
			rep(k,22)if(S[right][k] == '1') ++digsum[k];
			bool ok = true;
			rep(k,22)if(digsum[k] >= 2)ok = false;
			if(ok){
				++right;
			}else{
				rep(k,22)if(S[right][k] == '1') --digsum[k];
				break;
			}
		}
		ans += right - left;		
		if(right == left) ++right;
		else{
			rep(k,22)if(S[left][k] == '1') --digsum[k];
		}
	}
	cout << ans << endl;
	return 0;
}
