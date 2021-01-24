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
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N; cin>>N;
	vector<int> a(N);
	rep(i,N)cin>>a[i];
	map<int, int> rank;
	rep(i,N)rank[a[i]] = -1;
	int i = 0;
	for(auto x:rank){
		rank[x.first] = i;
		++i;
	}
	rep(i,N){
		cout<<rank[a[i]]<<endl;
	}
	return 0;
}