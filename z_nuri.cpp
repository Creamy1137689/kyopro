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

vector<vector<char>> nap(110, vector<char>(110,'o'));
int N;

void paint(int i){
	int c;
  REP(j,N){
		if(nap[i][j] == '.')c = j;
	}
	REP(j,c+1){
		nap[i][j] = 'o';
	}
	for(int j = c; j <= N; ++j){
		nap[i+1][j] = 'o';
	}
}

int main(){
	cin >> N;
	REP(i,N){
		REP(j,N){
			cin >> nap[i][j];
		}
	}
	int ans = 0;
	REP(i,N){
		REP(j,N){
			if(nap[i][j] == '.'){
				++ans;
				paint(i);
//				cout << line << endl;
//				REP(i,N){
//					REP(j,N)cout<<nap[i][j];
//					cout << endl;
//				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
