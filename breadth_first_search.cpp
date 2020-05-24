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
	int n;
	cin>>n;
	vector<int> ans(110,-1);
	vector<vector<int>> input (110);
	REP(i,n){
		int el_siz;
		cin>>el_siz>>el_siz;
		vector<int> el(el_siz);
		rep(j,el_siz)cin>>el[j];
		input[i] = el;
	}
	queue<int> Q;
	int cnt = 0;
	ans[1] = 0;
	Q.push(1);
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		rep(i,input[node].size()){
			if(ans[input[node][i]] == -1){
				ans[input[node][i]] = ans[node]+1;
				Q.push(input[node][i]);
			}
		}
	}
	REP(i,n)cout<<i<<' '<<ans[i]<<endl;
	return 0;
}
