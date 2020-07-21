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
	int N,p,A,B,cnt_a=0 ,cnt_b=0 ,cnt_c=0;
	cin>>N>>A>>B;
	rep(i,N){
		cin>>p;
		if(p <= A){
			++cnt_a;
		}else if(p <= B){
			++cnt_b;
		}else{
			++cnt_c;
		}
	}
	cout<<min({cnt_a, cnt_b, cnt_c})<<endl;
	return 0;
}
