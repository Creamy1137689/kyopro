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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N; cin>>N;
	string tar; cin>>tar;
	vector<string> mark(N);
	rep(i,N)cin>>mark[i];
	int ans = 0;
	rep(i,N){
		string com = mark[i];
		int siz = com.size();
		bool can = false;
		for(int k = 0; k<siz; ++k){
			for(int l = k+1; l<siz; ++l){
				if(com[k] == tar[0] && com[l] == tar[1]){
					int dis = l-k;
					bool ok = true;
					for(int m = 2; m<tar.size(); ++m){
						if(k+dis*m >= siz){ok = false; break;}
						if(com[k+dis*m] != tar[m]){
							ok = false; 
							break;
						}
					}
					if(ok){can = true; break;}
				}
			}
		}
		if(can) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}