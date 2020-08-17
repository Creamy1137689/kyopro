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
	int N;
	cin >> N;
	vector<P> blue(N);
	vector<P> red(N);
	rep(i,N)cin >> red[i].first >> red[i].second;
	rep(i,N)cin >> blue[i].first >> blue[i].second;
	sort(all(blue));
	vector<bool> red_used(N, false);
	int ans = 0;
	rep(i,N){
		int height = -1;
		int high_num = inf;
		rep(j,N){
			if(red[j].first < blue[i].first && !red_used[j]){
				if(red[j].second < blue[i].second && red[j].second > height){
					height = red[j].second;
					high_num = j;
				}
			}
		}
		if(high_num != inf){
			++ans;
			red_used[high_num] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
