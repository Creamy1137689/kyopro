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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N;
	cin>>N;
	char comb[5] = {'M','A','R','C','H'};
	vector<ll> name(30,0LL);
	rep(i,N){
		string s;
		cin>>s;
		name[s[0]-'A']++;
	}
	ll ans = 0LL;
	for(int i = 0; i<5; ++i){
		for(int j = i+1; j<5; ++j){
			for(int k = j+1; k<5; ++k){
				ans += name[comb[i]-'A'] * name[comb[j]-'A'] * name[comb[k]-'A'];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}