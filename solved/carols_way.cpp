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
	int nums[26] = {inf, 1, 1, 2, inf, 4, 9, 8, inf, 3, 8, 5, 7, 9, inf, 7, 4, 0, 
			6, 3, inf, 5, 2, 6, inf, 0};
	int N;
	cin >> N;
	vector<string> input(N);
	rep(i,N)cin >> input[i];
	bool al = false;
	rep(i,N){
		string ans;
		string from = input[i];
		rep(k, from.size())if('A' <= from[k] && from[k] <= 'Z')from[k] = (char)('a' + from[k]-'A');
		rep(k, from.size()){
			if(from[k] == '.' || from[k] == ',')continue;
			int code = nums[from[k] - 'a'];
			if(code == inf)continue;
			ans += (char)('0' + code);
		}
		if(ans == "")continue;
		if(!al){
			al = true;
		}else{
			cout<<' ';
		}
		cout<<ans;
	}
	cout<<endl;
	return 0;
}
