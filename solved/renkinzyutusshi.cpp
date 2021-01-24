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
#include <assert.h>
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

int main(){
	string s, t, u;
	cin >> s >> t >> u;
	int N = s.size()/2;
	vector<P> chara(26, make_pair(0,0));
	vector<int> need(26,0);
	rep(i,2*N){
		chara[s[i]-'A'].first ++;
		chara[t[i]-'A'].second ++;
		need[u[i]-'A']++;
	}
	int nax = 0;
	int nin = 0;
	rep(i,26){
		nin += max(0, need[i]-chara[i].second);
		nax += min(need[i], chara[i].first);
	}
	if(nin <= N && N <= nax){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
