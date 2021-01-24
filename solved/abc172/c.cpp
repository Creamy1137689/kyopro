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

bool isOK(ll a[], int index, ll key){
    if(a[index] > key) return true;
    else return false;
}

int binary_search(ll a[], int nax, ll key){
    int ng = -1;
    int ok =nax;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(a,mid,key))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	int N,M,K; cin>>N>>M>>K;
	vector<int> A(N);
	vector<int> B(M);
	rep(i,N)cin>>A[i];
	rep(i,M)cin>>B[i];
	ll suma[200200] = {0};
	ll sumb[200200] = {0};
	rep(i,N)suma[i+1] = suma[i] + A[i];
	rep(i,M)sumb[i+1] = sumb[i] + B[i];
	// rep(i,N+1)cout<<suma[i]<<' ';
	// cout<<endl;
	// rep(i,M+1)cout<<sumb[i]<<' ';
	// cout<<endl;
	int ans = 0;
	rep(i,N+1){
		ll t = K-suma[i];
		if(t < 0)continue;
		int add = binary_search(sumb, M+1, t)-1;
		// printf("[anum, bnum, t] = [%d, %d, %lld]\n", i, add, t);
		ans = max(ans, i + add);
	}
	cout<<ans<<endl;
}

// int main(){
// 	int N,M,K; cin>>N>>M>>K;
// 	vector<int> A(N+1);
// 	vector<int> B(M+1);
// 	rep(i,N)cin>>A[i]; A[N] = inf;
// 	rep(i,M)cin>>B[i]; B[M] = inf+2;
// 	int ap = 0, bp = 0;
// 	int ans = 0;
// 	while(A[ap] <= K || B[bp] <= K){
// 		if(A[ap] < B[bp]){
// 			K -= A[ap];
// 			++ans;
// 			++ap;
// 		}else if(A[ap] > B[bp]){
// 			K -= B[bp];
// 			++ans;
// 			++bp;
// 		}else{
// 			cout<<"in"<<endl;
// 			int tap = ap;
// 			int tbp = bp;
// 			while(A[tap] == B[tap]){
// 				if(K < A[tap])break;
// 				K -= A[tap];
// 				++tap; ++tbp; ++ans;
// 				// cout<<tap<<' '<<tbp<<endl;
// 			}
// 			if(A[tap] > B[tbp]){
// 				bp = tbp;
// 			}else{
// 				ap = tap;
// 			}
// 		}
// 		// printf("[ap, bp, K, ans] = [%d, %d, %d, %d]\n", ap, bp, K, ans);
// 	}
// 	cout<<ans<<endl;
// }

// int main(){
// 	int N, M, K; cin>>N>>M>>K;
// 	queue<int> A;
// 	queue<int> B;
// 	int t;
// 	rep(i,N){
// 		cin>>t;
// 		A.push(t);
// 	}
// 	rep(i,M){
// 		cin>>t;
// 		B.push(t);
// 	}
// 	int ans = 0;
// 	while(K <= A.front() || K <= B.front()){
// 		++ans;
// 		if(A.front() < B.front()){
// 			K -= A.front();
// 			A.pop();
// 		}else{
// 			K -= B.front();
// 			B.pop();
// 		}
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }