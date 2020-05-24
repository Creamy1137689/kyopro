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
	int T;
	cin>>T;
	REP(i,T){
		string input, ans;
		cin>>input;
		input += '0';
		int pre = 0;
		rep(p,input.size()){
			int dis = input[p]-'0'-pre;
			if(dis<0){
				rep(j,-dis)ans.push_back(')');
			}else if(dis>0){
				rep(j,dis)ans.push_back('(');
			}
			if(p == input.size()-1)break;
			ans.push_back(input[p]);
			pre = input[p] - '0';
		}
		printf("Case #%d: ", i);
		cout<<ans<<endl;
	}
	return 0;
}