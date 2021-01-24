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
	int t,N,M;
	vector<int> takoyaki(110, 0);
	cin >> t >> N;
	rep(i,N){
		int k;
		cin >> k;
		takoyaki[k] ++;
	}	
	cin >> M;
	vector<int> cust(M);
	rep(i,M)cin>>cust[i];
	rep(i,M){
		bool ok = false;
		int st = max(0, cust[i]-t);
		for( ; st <= cust[i]; ++st){
			if(takoyaki[st] > 0){
		 		--takoyaki[st];
				ok = true;
				break;
			}
		}
		if(!ok){cout<<"no"<<endl; return 0;}
	}
	cout<<"yes"<<endl;
	return 0;
}
