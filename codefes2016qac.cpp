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
	string s; int K;
	cin>>s>>K;
	rep(i,s.size()){
		if(i == s.size()-1){
			K %= 26;
			// cout<<K<<endl;
			int c = s[i] - 'a' + K;
			if(c >25)c -= 26;
			s[i] = (char)('a' + c);
			break;
		}
		if(s[i] == 'a')continue;
		int dist = 'z' - s[i] + 1;
		if(dist <= K){
			s[i] = 'a';
			K -= dist;
		}
	}
	cout<<s<<endl;
	return 0;
}