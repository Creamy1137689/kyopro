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
	int N,M,Q; cin>>N>>M>>Q;
	vector<int> scores(M,N);
	vector<vector<bool>> solved(N, vector<bool> (M,false));
	int com, n, m;
	rep(i,Q){
		cin>>com;
		if(com == 1){
			cin>>n;
			--n;
			int res = 0;
			rep(j,M){
				if(solved[n][j])res += scores[j];
			}
			cout<<res<<endl;
		}else{
			cin>>n>>m;
			--n; --m;
			scores[m]--;
			solved[n][m] = true;
		}
	}
	return 0;
}