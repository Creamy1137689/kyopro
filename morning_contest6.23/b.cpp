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
	vector<int> ans(6,0);
	rep(i,N){
		double nax,nin;
		cin>>nax>>nin;
		if(35 <= nax)ans[0]++;
		if(30 <= nax && nax < 35)ans[1]++;
		if(25 <= nax && nax < 30)ans[2]++;
		if(25 <= nin)ans[3]++;
		if(0 <= nax && nin < 0)ans[4]++;
		if(nax < 0)ans[5]++;
	}
	rep(i,6){
		cout<<ans[i];
		if(i < 5)cout<<' ';
	}
	cout<<endl;
	return 0;
}