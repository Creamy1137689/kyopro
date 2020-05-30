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
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

string s;

int main(){
	cin>>s;
	ll head = 0;
	ll ans = 0;
	for(int i = 0; i<s.size(); ++i){
		if(s[i] == 'A'){	
			while(s[i] == 'A'){
				++head; ++i;
			}
		}
		if(s[i] == 'B' && s[i+1] == 'C'){
			ans += head;
			i += 1;
		}else{
			head = 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}