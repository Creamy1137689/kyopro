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
	int N,L; cin>>N>>L;
	vector<string> amida(L+1);
	getline(cin, amida[0]);
	rep(i,L+1){getline(cin, amida[i]);}
	// rep(i,L+1)cout<<amida[i]<<endl;
	int pos;
	cout<<k<<endl;
	rep(i,amida[L].size()){
		if(amida[L][i]=='o'){
			pos = i;
		}
	}
	cout<<pos<<endl;
	cout<<k<<endl;
	// cout<<pos<<endl;
	for(int r = L-1; r>= 0; --r){
		rep(i,amida[0].size()){
			if(amida[r][i] == '-' && abs(pos-i) == 1){
				if(i > pos) pos += 2;
				else pos -= 2;
			}
		}
	}
	cout<<pos/2 + 1<<endl;
	return 0;
}
