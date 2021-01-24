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
const int MOD = (int)1e9 + 7;

bool check(map<int,int> a){
	if(a.size() == 2){
		vector<ip> t(2);
		int i = 0;
		for(auto x:a){
			t[i].first = x.first;
			t[i].second = x.second;
			++i;
		}
		ip x = t[0], y = t[1];
		if(max(x.second, y.second) != 2*min(x.second, y.second)){return false;}
		int nax, nin;
		if(x.second>y.second){
			nax = x.first;
			nin = y.first;
		}else{
			nax = y.first;
			nin = x.first;
		}
		// printf("[nax,nin] -> [%d,%d]\n",nax,nin);
		
		// int nax = max(t[0].first, t[1].first);
		// int nin = min(t[0].first, t[1].first);
		if((nax^nax) == nin && (nax^nin) == nax){return true;}
		else return false;
	}
	if(a.size() == 3){
		vector<int> t(3);
		vector<int> k(3);
		int i = 0;
		for(auto x:a){
			t[i] = x.first;
			k[i] = x.second;
			++i;
		}
		if(k[0] == k[1] && k[1] == k[2] && (t[1]^t[2]) == t[0]){return true;}
		else return false;
	}
	return false;
}

int main(){
	int N; cin>>N;
	vector<int> in(N);
	rep(i,N)cin>>in[i];
	map<int,int> cnt;
	rep(i,N){
		cnt[in[i]]++;
	}
	if(cnt.size() == 1 && cnt.count(0) == 1){cout<<"Yes"<<endl; return 0;}
	if(N%3 != 0){cout<<"No"<<endl; return 0;}
	if(cnt.size() <= 3 && check(cnt)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}