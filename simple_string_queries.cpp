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

int seg_len = 1;
int SEG_MAX = 10000000;
vector<map<char, int>> seg(SEG_MAX);

void seg_update(int pos, char c){
	pos += seg_len;
	while(pos > 0){
		seg[pos][c]++;
		pos /= 2;
	}
}

void seg_erase(int pos, char c){
	pos += seg_len;
	while(pos > 0){
		seg[pos][c]--;
		if(seg[pos][c] <= 0)seg[pos].erase(c);
		pos /= 2;
	}
}

int res(int l, int r){
	l += seg_len;
	r += seg_len;
	map<char,int> ret;
	while(l < r){
		if(l % 2 == 1){
			for(auto x:seg[l])ret[x.first] += x.second;
			++l;
		}
		if(r % 2 == 1){
			for(auto x:seg[r-1])ret[x.first] += x.second;
			--r;
		}
		l /= 2; r /= 2;
	}
	return ret.size();
}

int main(){
	int N, Q, i, l, r, tp;
	char c;
	string s;
	cin >> N >> s >> Q;
	while(seg_len < N)seg_len *= 2;
	rep(i,N)seg_update(i, s[i]);
	rep(_,Q){
		cin >> tp;
		if(tp == 1){
			cin >> i >> c;
			--i;
			seg_update(i,c);
			seg_erase(i,s[i]);
			s[i] = c;
		}else{
			cin >> l >> r;
			cout << res(l-1, r) << endl;
		}
	}
	//for(auto x: seg){
	//	for(auto y:x)cout << y.first << ' ';
	//	cout << endl;
	//}
	return 0;
}
