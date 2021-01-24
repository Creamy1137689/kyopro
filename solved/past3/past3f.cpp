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
	int N; cin>>N;
	vector<string> matr(N);
	rep(i,N)cin>>matr[i];
	string ans;
	for(int l = 0; l<N/2; ++l){
		int r = N-1-l;
		set<char> exist;
		rep(i,N){
			exist.insert(matr[l][i]);
		}
		bool ok = false;
		rep(i,N){
			if(exist.count(matr[r][i]) == 1){
				ans += matr[r][i];
				ok = true;
				break;
			}
		}
		if(!ok){
			cout<<-1<<endl; return 0;
		}
	}
	cout<<ans;
	if(N%2 == 1)cout<<matr[N/2][0];
	reverse(all(ans));
	cout<<ans<<endl;
	return 0;
}