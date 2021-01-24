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
	int N;
	cin>>N;
	bool ans = true;
	int cnt2 = 0;
	int cnt4 = 0;
	rep(i,N){
		int a;
		cin>>a;
		if(a%2==0 && a%4!=0)cnt2++;
		if(a%4==0)cnt4++;
	}
	int elses = N-cnt4-cnt2;
	if(cnt2>=2){
		if(cnt4<elses)ans = false;
	}else{
		if(cnt4<elses+cnt2-1)ans = false;
	}
	cout<<((ans)?"Yes":"No")<<endl;
	return 0;
}