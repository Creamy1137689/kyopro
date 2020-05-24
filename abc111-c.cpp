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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
	int n; cin>>n;
	vector<int> array(n);
	int V_MAX = 100100;
	vector<ip> ecnt(V_MAX);
	vector<ip> ocnt(V_MAX);
	rep(i,V_MAX){
		ecnt[i].first = i;
		ecnt[i].second = 0;
		ocnt[i].first = i;
		ocnt[i].second = 0;
	}
	rep(i,n){
		int t;
		cin>>t;
		if(i%2==0){
			ecnt[t].second++;
		}else{
			ocnt[t].second++;
		}
	}
	sort(all(ecnt),compare_by_b);
	sort(all(ocnt),compare_by_b);
	if(ecnt[V_MAX-1].first == ocnt[V_MAX-1].first){
		if(ecnt[V_MAX-1].second == ecnt[V_MAX-1].second){
			cout<<n - ecnt[V_MAX-1].second - max(ecnt[V_MAX-2].second, ocnt[V_MAX-2].second)<<endl;
		}else{
			int a,b;
			if(ecnt[V_MAX-1].second > ocnt[V_MAX-1].second){a = ecnt[V_MAX-1].second; b = ocnt[V_MAX-2].second;}
			else {a = ecnt[V_MAX-2].second; b = ocnt[V_MAX-1].second;}
			cout<<n - a - b<<endl;
		}
	}else{
		cout<<n - ecnt[V_MAX-1].second - ocnt[V_MAX-1].second<<endl;
	}
	return 0;
}
