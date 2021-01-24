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
	int N,Q; cin>>N>>Q;
	vector<int> column(N);
	vector<int> row(N);
	rep(i,N){
		column[i] = i+1;
		row[i] = i+1;
	}
	int com, a, b;
	bool rev = false;
	ll res;
	rep(i,Q){
		cin>>com;
		if(com == 1){
			cin>>a>>b;
			--a; --b;
			if(rev){
				swap(column[a], column[b]);
			}else{
				swap(row[a], row[b]);
			}
		}else if(com == 2){
			cin>>a>>b;
			--a; --b;
			if(rev){
				swap(row[a], row[b]);
			}else{
				swap(column[a], column[b]);
			}
		}else if(com == 3){
			rev = !rev;
		}else{
			cin>>a>>b;
			--a; --b;
			if(rev){
				res = (ll)N*(column[b]-1) + row[a]-1;
				cout<<res<<endl;
			}else{
				res = (ll)N*(row[a]-1) + column[b]-1;
				cout<<res<<endl;
			}
		}
		cout<<line<<endl;
		cout<<"| "; cout<<((rev)?"row":"col")<<' '; show(column);
		cout<<"| "; cout<<((rev)?"col":"row")<<' '; show(row);
		cout<<"| ";cout<<rev<<endl;
		cout<<line<<endl;
	}
	return 0;
}