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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	string sa,sb,sc;
	cin>>sa>>sb>>sc;
	vector<queue<int>> player(3);
	rep(i,sa.size()){
		int t = sa[i]-'a';
		player[0].push(t);
	}
	rep(i,sb.size()){
		int t = sb[i]-'a';
		player[1].push(t);
	}
	rep(i,sc.size()){
		int t = sc[i]-'a';
		player[2].push(t);
	}
	bool can = true;
	int p_num = 0;
	char ans;
	while(can){
		if(player[p_num].empty()){
			ans = (char)('A'+p_num);
			can = false;
		}
		// cout<<(char)('A'+p_num)<<endl;
		int nt = player[p_num].front();
		player[p_num].pop();
		p_num = nt;
	}
	cout<<ans<<endl;
	return 0;
}