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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N,a,b,c,d; cin>>N>>a>>b>>c>>d;
	--a; --b; --c; --d;
	string s; cin>>s;
	bool free_space = false;
	bool can = true;
	for(int i = min(a,b); i<max(c,d); ++i){
		if(s[i] == '#' && s[i+1] == '#')can = false;
		if(i>d || i<b)continue;
		if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.')free_space = true;
	}
	bool ans = false;
	if(c<d){
		if(can){ans = true;}
	}else{
		if(free_space && can){ans = true;}
	}
	cout<<((ans)?"Yes":"No")<<endl;
	return 0;
}