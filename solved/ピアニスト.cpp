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
	s += s;
	string to = "WWBWBWB";
	string ans[7] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
	int cnt = 0;
	rep(i,s.size()-7){
		string t = s.substr(i,7);
		if(t == to){
			cout<<ans[(9-cnt)%7]<<endl;
			break;
		}
		if(s[i] == 'W')cnt++;
	}
	return 0;
}