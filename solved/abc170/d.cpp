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

map<ll, ll> prime_factor(ll n){
    map<ll,ll> com;
    for(ll i = 2LL; i*i<=n; ++i){
        while(n%i==0LL){
            com[i]++;
            n /= i;
        }
    }
    if(n != 1LL)com[n]++;
    return com;
}

// int main(){
// 	int N; cin>>N;
// 	map<ll, ll> all_fact;
// 	vector<int> A(N);
// 	rep(i,N)cin>>A[i];
// 	rep(i,N){
// 		map<ll, ll> t = prime_factor(A[i]);
// 		for(auto x: t){
// 			all_fact[x.first] += x.second;
// 		}
// 		if(A[i] == 1){cout<<0<<endl; return 0;}
// 	}

// 	int ans = 0;
// 	sort(all(A), greater<int>());
// 	rep(i,N){
// 		map<ll, ll> t = prime_factor(A[i]);
// 		for(auto x: t){
// 			all_fact[x.first] -= x.second;
// 		}
// 		bool e_ans = true;
// 		for(auto x: t){
// 			if(all_fact.count(x.first) != 0)e_ans = false;
// 		}
// 		if(e_ans)++ans;
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }

int main(){
	int N; cin>>N;
	int ans = 0;
	vector<int> A(N);
	map<int,int> check;

	rep(i,N){
		cin>>A[i];
		check[A[i]]++;
	}
	rep(i,N){
		vector<int> fact;
		bool e_ans = true;
		for(int k = 1; k*k <= A[i];++k){
			if(A[i]%k == 0){
				fact.push_back(k);
				fact.push_back(A[i]/k);
			}
		}
		for(auto x: fact){
			if(x == A[i]){
				if(check[x] > 1)e_ans = false;
				continue;
			}
			if(check.count(x) == 1){e_ans = false;}
		}
		if(e_ans)ans++;
	}
	cout<<ans<<endl;
}