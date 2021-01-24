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

struct schedule{
	int s;
	int f;
	int no;
};

bool my_compare(schedule a, schedule b) {
    if(a.s != b.s){
        return a.s < b.s;
    }else{
        return a.f < b.f;
    }
}

int main(){
	int T;
	cin>>T;
	REP(i,T){
		int N;
		cin>>N;
		vector<schedule> task(N);
		rep(i,N){cin>>task[i].s>>task[i].f; task[i].no = i;}
		sort(all(task), my_compare);
		string ans;
		rep(i,N)ans.push_back('0');
		bool J = true;
		bool C = true;
		bool can = true;
		rep(j,1441){
			rep(k,N){
				if(j == task[k].s){
					if(J){ ans[task[k].no] = 'J'; J = false;}
					else if(C){ans[task[k].no] = 'C'; C = false;}
					else {can = false; ans = "IMPOSSIBLE"; break;}
				}
				if(j == task[k].f){
					if(ans[task[k].no] == 'J')J = true;
					else C = true;
				}
			}
			if(!can)break;
		}
		printf("Case #%d: ",i);
		cout<<ans<<endl;
	}
	return 0;
}