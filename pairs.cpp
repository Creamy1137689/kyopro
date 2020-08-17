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

ll N, K;
vector<ll> A(200200);
map<ll, int> exist;

ll calc_under(ll num, ll a){
	ll res = INF;
	ll need = INF;

	if(a > 0){
		if(num >= 0){
			need = num / a + (num % a != 0);
		}else{
			need = num / a;
		}
		auto it = lower_bound(all(A), need);
		res = it - A.begin();
		if(a < need)--res;
	}else if(a == 0){
		if(0 < num)res = N-1;
		else res =  0;
	}else{
		if(num >= 0){
			need = num / a - (num % a != 0);
		}else{
			need = num / a;
		}
		auto it = upper_bound(all(A), need);
		res = A.end() - it;
		if(a > need)--res;
	}

	//if(num == 1){
	//	printf("[a = %lld, need = %lld, res = %lld]\n", a, need, res);
	//}
	return res;
}

bool isOK(ll num){
	ll under = 0;
	ll same = 0;
	rep(i,N){
		under += calc_under(num, A[i]);
		if(A[i] != 0){
			if(num % A[i] == 0){
				same += exist[num / A[i]];
				if(A[i] == num / A[i])--same;
			}	
		}else{
			if(num == 0)same += N-1;
		}
	}
	under /= 2;
	same /= 2;
	//if(num == 1){
	//	printf("[num = %lld, under = %lld, same = %lld]\n", num, under, same);
	//}
	if(under >= K)return true;
	else{
		if(under + same >= K)return true;
		else return false;
	}
}

ll binary_search(){
	ll ng = -1e18 - 7;
	ll ok = 1e18 + 7;
	while(abs(ok-ng) > 1){
		ll mid = (ok + ng)/2;
		bool b = isOK(mid);
		//printf("[num = %lld -> %d]\n", mid, b);
		if(b)ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	cin >> N >> K;
	A.resize(N);
	rep(i,N){
		cin >> A[i];
		exist[A[i]] ++;
	}
	sort(all(A));
	cout << binary_search() << endl;
	return 0;
}
