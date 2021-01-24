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
	int N,a,b;
	cin>>N>>a>>b;
	int ans = 0;
	for(int cnt = 1; cnt<=N; ++cnt){
		int i = cnt;
		int sum = i%10;
		while(i/10 != 0){
			i /= 10;
			sum += i%10;
		}
		if(a <= sum && sum <= b)ans += cnt;
	}
	cout<<ans<<endl;
	return 0;
}