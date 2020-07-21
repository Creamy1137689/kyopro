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

int order[10] = {0};

bool left_is_bigger(int a, int b){
	if((int)log10(a) > (int)log10(b)){
		return false;
	}else if((int)log10(a) < (int)log10(b)){
		return true;
	}else{
		bool res = true;
		string aa = to_string(a), bb = to_string(b);
		// cout<<aa<<bb<<endl;
		rep(k, aa.size()){
			int ind_a, ind_b;
			rep(i,10)if(aa[k]-'0' == order[i])ind_a = i;
			rep(i,10)if(bb[k]-'0' == order[i])ind_b = i;
			// printf("[%d] -> [%d, %d]\n", k+1, ind_a, ind_b);
			if(ind_a > ind_b){res = false; break;}
			else if(ind_a < ind_b){break;}
		}
		return res;
	}
}

int main(){
	rep(i,10)cin>>order[i];
	int N; cin>>N;
	int array[N];
	rep(i,N)cin>>array[i];
	bool done = false;
	while(!done){
		done = true;
		rep(i,N-1){
			if(!left_is_bigger(array[i], array[i+1])){swap(array[i], array[i+1]); done = false;}
		}
	}
	rep(i,N)cout<<array[i]<<endl;
	return 0;
}

