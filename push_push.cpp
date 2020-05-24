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
	int N;
	cin>>N;
	deque<int> Q;
	int a;
	cin>>a;
	Q.push_back(a);
	rep(i,N-1){
		cin>>a;
		if(i%2==0){
			Q.push_back(a);
		}else{
			Q.push_front(a);
		}
	}
	if(N%2==1){
		reverse(all(Q));
	}
	rep(i,N){
		cout<<Q.back()<<' ';
		Q.pop_back();
	}
	cout<<endl;
	return 0;
}