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

int main(){
	int N, dist;
	cin >> N;
	int x = inf, y = inf;
	int max_x = -1, max_y = -1;
	for(int i = 2; i <= N; ++i){
		cout << "? " << 1 << " " << i << endl;
		cin >> dist;
		if(dist > max_x){
			max_x = dist;
			x = i;
		}
	}

	for(int i = 1; i <= N; ++i){
		if(i == x)continue;
		cout << "? " << x << " " << i << endl;
		cin >> dist;
		if(dist > max_y){
			max_y = dist;
			y = i;
		}
	}
	cout << "!" << ' ' << max_y << endl;
	return 0;
}
