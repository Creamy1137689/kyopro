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
	int N,M;
	cin>>N>>M;
	vector<ip> in(M);
	rep(i,M){
		cin>>in[i].first>>in[i].second;
	}
	int start = 1 * pow(10,N-1);
	if(start ==1)start = 0;
	int end = pow(10,N)-1;
	int ans = -1;
	// cout<<start<<' '<<end<<endl;
	for(; start<=end; ++start){
		bool ok = true;
		// cout<<"----"<<endl;
		rep(i,M){
			int digit = start/(int)pow(10,N-in[i].first)%10;
			// cout<<(int)pow(10,N-in[i].first)<<endl;
			if(digit != in[i].second) ok = false;
		}
		// cout<<"----"<<endl;
		if(ok){ans = start; break;}
	}	
	cout<<ans<<endl;
	return 0;
}