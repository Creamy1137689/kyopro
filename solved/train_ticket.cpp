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
	string s;
	cin>>s;
	int a,b,c,d;
	a = s[0]-'0';
	b = s[1]-'0';
	c = s[2]-'0';
	d = s[3]-'0';
	if(a+b+c+d==7){printf("%d+%d+%d+%d=7\n",a,b,c,d); return 0;}
	if(a+b+c-d==7){printf("%d+%d+%d-%d=7\n",a,b,c,d); return 0;}
	if(a+b-c+d==7){printf("%d+%d-%d+%d=7\n",a,b,c,d); return 0;}
	if(a+b-c-d==7){printf("%d+%d-%d-%d=7\n",a,b,c,d); return 0;}
	if(a-b+c+d==7){printf("%d-%d+%d+%d=7\n",a,b,c,d); return 0;}
	if(a-b+c-d==7){printf("%d-%d+%d-%d=7\n",a,b,c,d); return 0;}
	if(a-b-c+d==7){printf("%d-%d-%d+%d=7\n",a,b,c,d); return 0;}
	if(a-b-c-d==7){printf("%d-%d-%d-%d=7\n",a,b,c,d); return 0;}
	return 0;
}