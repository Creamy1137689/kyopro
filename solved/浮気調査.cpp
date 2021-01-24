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
	ip bf, now;
	int T,V,n;
	cin>>bf.first>>bf.second>>now.first>>now.second>>T>>V>>n;
	vector<ip> girls(n);
	rep(i,n)cin>>girls[i].first>>girls[i].second;
	int max_length = T*V;
	bool ans = false;
	rep(i,n){
		double length = sqrt(pow(abs(bf.first-girls[i].first),2) + pow(abs(bf.second-girls[i].second),2));
		length += sqrt(pow(abs(now.first-girls[i].first),2) + pow(abs(now.second-girls[i].second),2));
		if(max_length>= length)ans = true;
	}
	cout<<((ans)?"YES":"NO")<<endl;
	return 0;
}