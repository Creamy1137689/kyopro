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
	string s; cin>>s;
	int N = s.size();
	map<char, int> cnt;
	priority_queue<int, vector<int>, greater<int>> seed;
	queue<int> clay;

	rep(i,N)cnt[s[i]]++;
	for(auto x: cnt){
		if(x.second % 2 == 1){
			seed.push(1);
			if(x.second > 2)clay.push(x.second -1);
		}else{
			clay.push(x.second);
		}
	}
	if(seed.size() == 0){cout<<N<<endl; return 0;}
	while(!clay.empty()){
		int t = clay.front();
		int ob = seed.top();
		clay.pop();
		seed.pop();
		ob += 2;
		t -= 2;
		seed.push(ob);
		if(t > 1)clay.push(t);
	}
	cout<<seed.top()<<endl;
	return 0;
}