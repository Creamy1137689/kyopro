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
	int a,b,c;
	cin>>a>>b>>c;
	int perm[9] = {1,2,3,4,5,6,7,8,9};
	int ans = 0;
	do{
		bool ok = true;
		// rep(i,a+b+c)cout<<perm[i]<<' ';
		// cout<<endl;
		for(int i = 1; i<a; ++i){
			// cout<<"first"<<endl;
			if(perm[i]<perm[i-1])ok = false;
		}
		if(perm[a]<perm[0])ok = false;
		for(int i = a+1; i<a+b; ++i){
			// cout<<"second"<<endl;
			if(perm[i]<perm[i-1] || perm[i] < perm[i-a])ok = false;
		}
		if(perm[a+b]<perm[a])ok = false;
		for(int i = a + b + 1; i<a+b+c; ++i){
			// cout<<"third"<<endl;
			if(perm[i]<perm[i-1] || perm[i] < perm[i-b])ok = false;
		}
		if(ok)ans++;
	}while(next_permutation(perm, perm+a+b+c));
	cout<<ans<<endl;
	return 0;
}