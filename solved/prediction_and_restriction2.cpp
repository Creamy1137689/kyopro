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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int N, K, R, S, P;

int score(char t){
	if(t == 'p')return S;
	if(t == 's')return R;
	if(t == 'r')return P;
	return 0;
}

int main(){
	string input;
	cin >> N >> K >> R >> S >> P >> input;
	vector<bool> used(N, false);
	ll ans = 0;
	rep(i,N){
		if(i >= K){
			if(input[i] == input[i-K]){
				if(!used[i-K]){
					ans += score(input[i]);
					used[i] = true;
				}
			}else{
				ans += score(input[i]);
				used[i] = true;
			}
		}else{
			ans += score(input[i]);
			used[i] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
