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
	vector<ip> ship(M);
	set<int> from1;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		if(a==1)from1.insert(b);
		ship[i].first = a;
		ship[i].second = b;
	}
	bool ok = false;
	rep(i,M){
		if(ship[i].second == N){
			if(from1.count(ship[i].first)==1){
				ok = true;
			}
		}
	}
	cout<<((ok)?"POSSIBLE":"IMPOSSIBLE")<<endl;
	return 0;
}