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
	vector<string> D(N);
	rep(i,N)cin>>D[i];
	vector<bool> days(366);
	rep(i,366){
		if(i % 7 == 0)days[i] = true;
		if(i % 7 == 6)days[i] = true;
	}
	int monthday[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sum[13] = {0};
	rep(i,12)sum[i+1] = sum[i] + monthday[i];
	vector<int> input(N);
	rep(i,N){
		int m, d, ind;
		string s = D[i];
		if(s[1] == '/'){
			m = atoi(s.substr(0,1).c_str());
			d = atoi(s.substr(2, s.size()-2+1).c_str());
		}else{
			m = atoi(s.substr(0,2).c_str());
			d = atoi(s.substr(3, s.size()-3+1).c_str());
		}
		ind = sum[m-1] + d-1;
		input[i] = ind;
	}
	sort(all(input));
	rep(i,N){
		int ind = input[i];
		bool ok = true;
		while(ok){
			if(days[ind] == false){
				days[ind] = true;
				ok = false;
			}else{
				++ind;
			}
			if(ind > 365){ok = false;}
		}
	}
	int nax = -inf;
	int now = 0;
	rep(i,366 ){
		if(days[i]){
			++now;
		}else{
			nax = max(nax, now);
			now = 0;
		}
	}
	nax = max(nax, now);
	cout<<nax<<endl;
	return 0;
}