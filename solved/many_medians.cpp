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

bool compare_by_b(pair<ip, bool> a, pair<ip, bool> b) {
    if(a.first.second != b.first.second){
        return a.first.second < b.first.second;
    }else{
        return a.first.first < b.first.first;
    }
}

int main(){
	int n;
	cin>>n;
	vector<pair<ip,bool>> x(n);
	rep(i,n){
		int a;
		cin>>a;
		x[i].first.first = a;
		x[i].first.second = i;
		x[i].second = false;
	}
	sort(all(x));
	int left = x[n/2-1].first.first;
	int right = x[n/2].first.first;
	for(int i = 0; i<n/2; i++)x[i].second = true;
	sort(all(x),compare_by_b);
	rep(i,n)cout<<((x[i].second)?right:left)<<endl;
	return 0;
}