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

int main(){
	int N; cin>>N;
	vector<int> A(N);
	vector<int> ans(N,0);
	int nax = 0;
	rep(i,N){
		cin>>A[i];
		nax = max(nax, A[i]);
	}
	for(int bit = 0; pow(2,bit-1)<nax; ++bit){
		int cnt = 0;
		vector<bool> is(N,false);
		rep(i,N){
			if(A[i] & (1<<bit)){
				cnt++;
				is[i] = true;
			}
		}
		if(cnt%2 == 0){
			rep(i,N){
				if(is[i]){
					ans[i] += pow(2,bit);
				}
			}
		}else{
			rep(i,N){
				if(!is[i]){
					ans[i] += pow(2,bit);
				}
			}
		}
	}
	show(ans);
	return 0;
}