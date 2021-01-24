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
	int N,D,K;
	cin>>N>>D>>K;
	vector<P> sch(D);
	vector<P> path(K);
	rep(i,D){
		cin>>sch[i].first>>sch[i].second;
	} 
	rep(i,K){
		cin>>path[i].first>>path[i].second;
	}
	int L,R,now,dist;
	rep(i,K){
		now = path[i].first;
		dist = path[i].second;
		rep(j,D){
			L = sch[j].first;
			R = sch[j].second; 
			if(now > dist){
				if(L<= now && now <= R)now = L;
			}else{
				if(L<= now && now <= R)now = R;
			}
			if(L <= now && now <= R && L <= dist && dist <= R){
				cout<<j+1<<endl;
				break;
			}
		}
	}
	return 0;
}