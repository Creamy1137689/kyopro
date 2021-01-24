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
	int N, M;
	string name, kit;
	cin >> N >> M >> name >> kit;
	map<char, int> name_cnt;
	map<char, int> kit_cnt;
	rep(i,N)name_cnt[name[i]]++;
	rep(i,M)kit_cnt[kit[i]]++;
	int ans = 0;
	for(auto x: name_cnt){
		int inkit = kit_cnt[x.first];
		//printf("%c -> [%d(name), %d(kit)]\n", x.first, x.second, inkit);
		if(inkit == 0){
			cout<<-1<<endl;
			return 0;
		}
		ans = max(ans, x.second/inkit + (x.second % inkit != 0));
	}
	cout<<ans<<endl;
		return 0;
}
