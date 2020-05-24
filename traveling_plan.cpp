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
	int N;
	cin>>N;
	int sum = 0;
	vector<int> pos(N+2,0);
	REP(i,N){
		int a;
		cin>>a;
		pos[i] = a;
		sum += abs(a-pos[i-1]);
	}
	sum += abs(pos[N]);
	REP(i,N){
		int rest = abs(pos[i+1]-pos[i]) + abs(pos[i]-pos[i-1]) - abs(pos[i+1]-pos[i-1]);
		cout<<sum-rest<<endl;
	}
	return 0;
}