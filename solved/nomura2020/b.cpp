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

string s;

void solve( int pos){
	if(pos != 0){
		if(s[pos-1] == '?'){
			if(s[pos]== 'D'){
				s[pos-1] = 'P';
			}else{
				s[pos-1] = 'D';
			}
			solve(pos-1);
		}
	}
	if(pos != s.size()-1){
		if(s[pos+1] == '?'){
			if(s[pos]== 'D'){
				s[pos+1] = 'P';
			}else{
				s[pos+1] = 'D';
			}
			solve(pos+1);
		}
	}
}

int main(){
	cin>>s;
	rep(i, s.size()){
		if(s[i] == '?')s[i] = 'D';
	}
	// rep(i,s.size()){
	// 	if(s[i] != '?'){
	// 		solve(i);
	// 	}
	// }	
	cout<<s<<endl;
	return 0;
}