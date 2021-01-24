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

string s;

bool check(int l, int r){
	int rev;
	//cout<<l<<' '<<r<<endl;
	if((r-l+1)%2==0){
		rev = (r-l+1)/2;
	}else{
		rev = (r-l+1)/2+1;
	}
	stack<char> S;
	rep(i,(r-l+1)/2){
		S.push(s[i+l]);
	}
	rev +=l;
	//cout<<rev<<endl;
	for(int i = rev; i<=r; i++){
		char t = S.top();
		S.pop();
		if(s[i] == t)continue;
		return false;
	}
	return true;
}

int main(){
	cin>>s;
	int n = s.size()-1;
	//cout<<n<<endl;
	//cout<<((check((n+3)/2,n))?"Yes":"No")<<endl;
	
	if(check(0,n) && check(0,(n-1)/2) && check((n+3)/2,n)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	return 0;
}
