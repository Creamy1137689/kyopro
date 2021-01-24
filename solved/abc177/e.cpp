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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

vector<int> min_primefactor(10000000, inf);

void calc(){
	min_primefactor[0] = 0;
	min_primefactor[1] = 1;
	for(int i = 2; i < 10000000; ++i){
		if(min_primefactor[i] == inf){
			for(int k = 1; i * k < 10000000; ++k){
				min_primefactor[i * k] = i;
			}
		}
	}
}

map<int,int> prime_factor(int N){
	map<int, int> res;
	while(N > 1){
		res[min_primefactor[N]]++;
		N /= min_primefactor[N];
	}
	return res;
}

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> used(1000100,false);
	rep(i,N)cin >> A[i];
	calc();
	bool is_setwise = false;
	bool is_pairwise = true;
	int g = A[0];
	for(int i = 1; i < N; ++i)g = gcd(g, A[i]);
	if(g == 1)is_setwise = true;
	set<int> exist;
	rep(i,N){
		map<int,int> m = prime_factor(A[i]);
		for(auto x:m){
			if(exist.count(x.first) != 0){
				is_pairwise = false;
				break;
			}else{
				exist.insert(x.first);
			}
		}
	}
	if(is_pairwise)cout << "pairwise coprime" << endl;
	else if(is_setwise)cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl;
	return 0;
}
