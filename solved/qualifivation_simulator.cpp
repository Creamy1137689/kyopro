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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N,A,B;
	cin>>N>>A>>B;
	int nax = A+B;
	int cnt_b = 0;
	string s;cin>>s;
	rep(i,N){
		if(nax==0){cout<<"No"<<endl; continue;}
		char c = s[i];
		if(c == 'b')cnt_b++;
		if(c == 'a'){
			cout<<"Yes"<<endl; --nax;
			continue;
		}
		if(c == 'b' && cnt_b<=B){
			cout<<"Yes"<<endl; --nax;
			continue;
		}
		cout<<"No"<<endl;
	}
	return 0;
}