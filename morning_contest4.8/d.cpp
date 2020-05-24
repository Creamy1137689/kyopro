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
	string m = "maerd";
	string rd = "remaerd";
	string e = "esare";
	string re = "resare";
	string s;
	cin>>s;
	reverse(all(s));
	bool ok = true;
	int p = 0;
	while(s.size() > p){
		if(s.substr(p, 5) == m){
			p += 5;
		}else if(s.substr(p,7) == rd){
			p += 7;
		}else if(s.substr(p,6) == re){
			p += 6;
		}else if(s.substr(p,5) == e){
			p += 5;
		}else{
			ok = false; break;
		}
	}
	cout<<((ok)?"YES":"NO")<<endl;
	return 0;
}