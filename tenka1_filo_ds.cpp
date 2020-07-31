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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	ll Q, L;
	cin >> Q >> L;
	stack<P> S;
	ll siz = 0;
	string q;
	int N,M;
	rep(_,Q){
		cin >> q;
		if(q == "Push"){
			cin >> N >> M;
			if(siz + N > L){
				cout << "FULL" << endl;
				return 0;
			}else{
				siz += N;
			}
			S.push(make_pair(M, N));
		}else if(q == "Pop"){
			cin >> N;
			if(N > siz){
				cout << "EMPTY" << endl;
				return 0;
			}
			siz -= N;
			while(N > 0){
				if(N >= S.top().second){
					N -= S.top().second;
					S.pop();
				}else{
					S.top().second -= N;
					N = 0;
				}
			}
		}else if(q == "Top"){
			if(siz == 0){
				cout << "EMPTY" << endl;
				return 0;
			}
			cout << S.top().first << endl;
		}else if(q == "Size"){
			cout << siz << endl;
		}
	}
	cout << "SAFE" << endl;
	return 0;
}
