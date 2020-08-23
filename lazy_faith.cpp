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

bool isOK(vector<ll> &a, ll index, ll key){
	if(a[index] >= key) return true;
	else return false;
}

int binary_search(vector<ll> &sfor, ll key){
	ll ng = -1;
	ll ok = sfor.size();
	while(abs(ok-ng) > 1){
		int mid = (ok + ng)/2;
		if(isOK(sfor,mid,key))ok = mid;
		else ng = mid;
	}
	return ok;
}

LP dist(vector<ll> &f, ll st){
	int f_pos = binary_search(f, st);
	ll f_dis_f = INF, f_dis_b = INF;
	if(f_pos != f.size())f_dis_f = f[f_pos];
	if(f_pos != 0)f_dis_b = f[f_pos-1];
	return make_pair(f_dis_f, f_dis_b);
}

ll dist(vector<ll> &fst, vector<ll> &scd, ll st){
	ll res1 = 0, res2 = 0, res3 = 0, res4 = 0;
	LP first_place = dist(fst, st);
	res1 = res2 = abs(st - first_place.first);
	res3 = res4 = abs(st - first_place.second);
	LP second_place1 = dist(scd, first_place.first);
	LP second_place2 = dist(scd, first_place.second);
	res1 += abs(second_place1.first - first_place.first);
	res2 += abs(second_place1.second - first_place.first);
	res3 += abs(second_place2.first - first_place.second);
	res4 += abs(second_place2.second - first_place.second);
	return min({res1, res2, res3, res4});
}

int main(){
	ll A, B, Q;
	cin >> A >> B >> Q;
	vector<ll> shrine(A);
	vector<ll> temple(B);
	vector<ll> querys(Q);
	rep(i,A)cin >> shrine[i];
	rep(i,B)cin >> temple[i];
	rep(i,Q)cin >> querys[i];
	rep(i,Q){
		ll now = querys[i];
		cout << min(dist(shrine, temple, now), dist(temple, shrine, now)) << endl;
	}
	return 0;
}
