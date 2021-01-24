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
	int H,W; cin>>H>>W;
	map<char, int> input;
	char c;
	rep(i,H*W){
		cin>>c;
		input[c]++;
	}
	priority_queue<int> Q;
	while(H > 0 && W > 0){
		int cnt4 = 0;
		int cnt2 = 0;
		if(H == 1 && W == 1){
			Q.push(1);
			--H; --W;
		}
		bool er_h = false, er_w = false;
		if(H>1){
			cnt4 += W/2;
			cnt2 += W%2;
			er_h = true;
		}
		if(W>1){
			cnt4 += H/2;
			cnt2 += H%2;
			er_w = true;
		}
		if(er_h)H -= 2;
		if(er_w)W -= 2;
		if(cnt4>0)cnt4--;
		rep(i,cnt4)Q.push(4);
		rep(i,cnt2)Q.push(2);
	}
	bool ok = true;
	while(!Q.empty()){
		int t = Q.top();
		Q.pop();
		bool can = false;
		for(auto x: input){
			if(x.second >= t){
				input[x.first] -= t;
				can = true;
				break;
			}
		}
		if(!can)ok = false;
		// for(auto x: input)cout<<x.first<<' '<<x.second<<endl;
	}
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}