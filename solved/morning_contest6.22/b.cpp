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
	int N ; cin>>N;
	vector<int> H(N);
	rep(i,N)cin>>H[i];
	bool ok = true;
	for(int i = N-1; i>0; --i){
		if(H[i-1]-H[i] > 1){ok = false; break;}
		if(H[i-1]-H[i] == 1)H[i-1]--;
	}
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}