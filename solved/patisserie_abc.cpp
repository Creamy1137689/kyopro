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
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

struct status{
	ll b;
	ll d;
	ll p;
};

ll ord(ll t){
	return ((t == 0) ? 1 : -1);
}

ll calc_value(status item, int i, int j, int k){
	int ob = ord(i), od = ord(j), op = ord(k);
	return item.b * ob + item.d * od + item.p * op;
}

int main(){
	int N, M; 
	cin >> N >> M;
	vector<status> item(N);
	rep(i,N)cin >> item[i].b >> item[i].d >> item[i].p;
	ll ans = -1;
	rep(i,2)rep(j,2)rep(k,2){
		vector<pair<ll, int>> values(N);
		rep(l, N){
			values[l].first = calc_value(item[l], i, j, k);
			values[l].second = l;
			//if(l == 0){
			//	printf("[i,j,k = %d, %d, %d]->[values[0] = %lld]\n", i, j, k, values[l].first );
			//}
		}
		sort(all(values), greater<pair<ll,int>>());
		ll sum_b = 0, sum_d = 0, sum_p = 0;
		rep(l,M){
			int item_num = values[l].second;
			sum_b += item[item_num].b * ord(i);
			sum_d += item[item_num].d * ord(j);
			sum_p += item[item_num].p * ord(k);
		}
		ans = max(ans, abs(sum_b) + abs(sum_d) + abs(sum_p));
	}
	cout << ans << endl;
	return 0;
}
