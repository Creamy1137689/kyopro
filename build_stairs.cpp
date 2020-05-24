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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n; cin>>n;
	int maxh;
	cin>>maxh;
	bool ans = true;
	bool al = false;
	rep(i,n-1){
		int nowh;
		cin>>nowh;
		if(maxh-1>nowh){
			ans = false;
			break;
		}
		if(maxh-1==nowh){
			al = true;
			continue;
		}
		if(maxh<nowh){
			maxh = nowh;
			al = false;
		}
	}
	cout<<((ans)?"Yes":"No")<<endl; return 0;
}
