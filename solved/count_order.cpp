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
	int n;
	cin>>n;
	vector<int> p(n), q(n);
	rep(i,n)cin>>p[i];
	rep(i,n)cin>>q[i];
	int perm[8] = {1,2,3,4,5,6,7,8};
	int cnt = 0;
	int p_pos, q_pos;
	do{
		++cnt;
		bool p_ok = true, q_ok = true;
		rep(i,n){
			if(perm[i] != p[i])p_ok = false;
			if(perm[i] != q[i])q_ok = false;
		}
		if(p_ok)p_pos = cnt;
		if(q_ok)q_pos = cnt;
	}while(next_permutation(perm, perm+n));
	cout<<abs(p_pos-q_pos)<<endl;
	return 0;
}
