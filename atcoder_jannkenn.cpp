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

int opponent(int i){
	if(i == 1)return 2;
	else if(i == 2)return 3;
	else return 1;
}

int main(){
	int N;
	ll r, h;
	cin >> N;
	vector<LP> part(N);
	vector<ll> rates(N);
	map<LP, int> ch;
	rep(i,N){
		cin >> r >> h;
		part[i] = make_pair(r,h);
		rates[i] = r;
		ch[part[i]] ++;
	}
	sort(all(rates));
	rep(i,N){
		int win = lower_bound(all(rates), part[i].first) - rates.begin() + ch[make_pair(part[i].first, opponent(part[i].second))];
		int even = ch[make_pair(part[i].first, part[i].second)] - 1;
		int lose = N - even - win - 1;
		printf("%d %d %d\n", win, lose, even);
	}
	return 0;
}
