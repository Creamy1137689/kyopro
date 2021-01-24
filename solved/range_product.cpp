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
	ll a,b;
	cin>>a>>b;
	if(a*b<=0){cout<<"Zero"<<endl; return 0;}
	if(a>0){cout<<"Positive"<<endl; return 0;}
	if(!((b-a+1)%2))cout<<"Positive"<<endl;
	else cout<<"Negative"<<endl;

	// if(0<a && a<=b){cout<<"Positive"<<endl; return 0;}
	// if(b<0){
	// 	if((b-a+1)%2){cout<<"Negative"<<endl;}
	// 	else {cout<<"Positive"<<endl;}
	// 	return 0;
	// }
	// cout<<"Zero"<<endl;
	return 0;
}