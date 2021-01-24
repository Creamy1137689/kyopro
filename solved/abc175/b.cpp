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
	int N;
	cin >> N;
	vector<int> L(N);
	rep(i,N)cin >> L[i];
	int ans = 0;
	for(int i = 0; i < N; ++i){
		for(int j = i + 1; j < N; ++j){
			for(int k = j + 1; k < N; ++k){
				int a = L[i], b = L[j], c = L[k];
				if(a != b && b != c && c != a && a + b > c && b + c > a && c + a > b)++ans;
			}
		}
	}
	cout << ans << endl;
		return 0;
}
