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

bool finished(string s){
	rep(i,s.size()){
		if(s[i] == '.')return false;
	}
	return true;
}

int main(){
	int N,R;
	string s;
	cin>>N>>R>>s;
	int ans  = 0;
	int i = N-1;
	vector<bool> gun(s.size(), false); 
	while(!finished(s) && i >= 0){
		// cout<<i<<endl;
		if(s[i] == '.'){
			s[i] = 'o';
			for(int k = 0; k < R-1 && i > 0; ++k){
				--i;
				s[i] = 'o';
			}
			ans ++;
			gun[i] = true;
		}else{
			--i;
		}
		// for(auto x: gun)cout<<x<<' '; cout<<s<<endl;
	}
	int cnt = ans;
	rep(i,N){
		if(cnt<= 0){break;}
		if(gun[i]){
			--cnt;
			if(cnt <= 0){break;}
		}
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}