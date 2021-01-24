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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N; cin>>N;
	vector<ll> a(N), b(N);
	ll sum_a = 0, sum_b = 0;
	rep(i,N){
		cin>>a[i];
		sum_a += a[i];
	}
	rep(i,N){
		cin>>b[i];
		sum_b += b[i];
	}
	ll disp = sum_b - sum_a;
	ll conf_a = 0;
	ll conf_b = 0;
	ll discount = 0;
	rep(i,N){
		if(a[i] == b[i])continue;
		if(a[i]>b[i]){
			ll rent = min(conf_b, a[i]-b[i]);
			conf_b -= rent;
			b[i] += rent;
			ll ope = a[i]-b[i];
			discount += ope;
			conf_a += ope*2;
		}else if(a[i]%2 == b[i]%2){
			ll rent = min(conf_a, b[i]-a[i]);
			conf_a -= rent;
			a[i] += rent;
			ll ope = (b[i]-a[i])/2;
			discount += ope;
			conf_b += ope;
		}else{
			if(conf_b == 0){
				conf_a += 2;
				discount ++;
				b[i]++;
			}else{
				conf_b--;
				b[i]++;
			}
			ll rent = min(conf_a, b[i]-a[i]);

			conf_a -= rent;
			a[i] += rent;
			ll ope = (b[i]-a[i])/2;
			discount += ope;
			conf_b += ope;
		}
		// printf("[%d]:<conf_a, conf_b> = [%lld, %lld]\n",i,conf_a, conf_b);
	}
	bool ans = true;
	conf_a += 2*max(0LL,disp-discount);
	conf_b += max(0LL, disp-discount);
	// cout<<conf_a<<' '<<conf_b<<endl;
	if(discount>disp)ans = false;
	if(conf_a != conf_b)ans = false;
	cout<<((ans)?"Yes":"No")<<endl;
	return 0;
}

// int main(){
// 	ll N; cin>>N;
// 	vector<ll> a(N);
// 	vector<ll> b(N);
// 	ll sa = 0, sb = 0; 
// 	rep(i,N){cin>>a[i]; sa += a[i];}
// 	rep(i,N){cin>>b[i]; sb += b[i];}
// 	ll dif = 0;
// 	rep(i,N)if(a[i]%2 != b[i]%2) ++ dif;
// 	bool ans;
// 	ll dis = 0;
// 	rep(i,N)if(a[i]>b[i])dis += a[i]-b[i];
// 	ll dis2 = 0;
// 	rep(i,N)if(a[i]<b[i])dis2 += b[i]-a[i];
// 	if(sb-sa < 0 || abs(sb-sa)%2 != dif%2 || dis > abs(sb-sa) || dis2 > abs(sb-sa)*2)ans = false;
// 	else ans = true;
	
// 	cout<<((ans)?"Yes":"No")<<endl;
// 	return 0;
// }