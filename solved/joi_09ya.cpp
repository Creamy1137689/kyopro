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
	int hi,mi,si,he,me,se,ti,te;
	rep(i,3){
		cin>>hi>>mi>>si>>he>>me>>se;
		ti = 60*60*hi + 60*mi + si;
		te = 60*60*he + 60*me + se;
		int stay = te-ti;
		printf("%d %d %d\n", stay/3600, stay/60%60, stay%60);
	}
	return 0;
}