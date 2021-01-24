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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int k;
	cin>>k;
	vector<ip> qs(k);
	rep(i,k)cin>>qs[i].first>>qs[i].second;
	int perm[8] = {0,1,2,3,4,5,6,7};
	do{
		bool req = true;
		rep(i,k){
			if(perm[qs[i].second] != qs[i].first){
				req = false;
				break;
			}
		}
		if(!req)continue;
		bool ok = true;
		rep(i,8){
			int x = i, y = perm[i];
			int sum = x+y;
			for(int j = sum; j>=0; --j){
				if(j == i)continue;
				if(perm[j] == sum-j){
					ok = false;
					break;
				}
			}
			if(!ok)break;
			int dx = x-1, dy = y-1;
			while(dx>=0 && dy>=0){
				if(perm[dx] == dy){
					ok = false;
					break;
				}
				--dx;
				--dy;
			}
			if(!ok)break;
			dx = x+1, dy = y+1;
			while(dx<8 && dy<8){
				if(perm[dx] == dy){
					ok = false;
					break;
				}
				++dx;
				++dy;
			}
		}
		if(ok){
			rep(i,8){
				rep(j,8){
					if(perm[j] == i)cout<<'Q';
					else cout<<'.';
				}
				cout<<endl;
			}
			return 0;
		}
	}while(next_permutation(perm,perm+8));
}