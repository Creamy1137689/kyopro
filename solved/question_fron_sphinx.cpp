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
	int N,M; cin>>N>>M;
	for(int i = 0; i*3 <= M; ++i){
		if((M-i*3)%2 == 0){
			int leg = M - i*3;
			int pep = N - i;
			int bab = leg/2 - pep;
			int ad = pep-bab;
			if(bab >= 0 && ad >= 0){
				cout<<ad<<' '<<i<<' '<<bab<<endl; 
				return 0;
			}
		}
	}
	cout<<"-1 -1 -1"<<endl;
	return 0;
}