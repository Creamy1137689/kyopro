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
	int l = 0, r = N;
	vector<string> seat(N+1);
	string res, left_ideal, right_ideal;
	int left_dis;
	int query = 0;
	int next;

	cout<<query<<endl;
	cin>>res;
	if(res == "Vacant"){return 0;}
	seat[0] = res;
	seat[N] = res;
	query = (r+l)/2;
	while(true){
		cout<<query<<endl;
		cin>>res;
		seat[query] = res;

		if(res == "Vacant"){return 0;}
		left_dis = query-l;
		if(left_dis % 2 == 1){
			if(seat[l] == "Male"){ left_ideal = "Female"; }
			else{ left_ideal = "Male"; }
		}else{
			if(seat[l] == "Male"){ left_ideal = "Male"; }
			else{ left_ideal = "Female"; }
		}

		if(res == left_ideal){
			l = query;
			query = (r+l)/2;
		}else{
			r = query;
			query = (r+l)/2;
		}
	}
	return 0;
}