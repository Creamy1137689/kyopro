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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
	int n; cin>>n;
	vector<ip> score(n);
	vector<int> grade(n);
	rep(i,n){
		int t; cin>>t;
		score[i].first = t;
		score[i].second = i;
	}
	sort(all(score),greater<ip>());
	rep(i,n){
		if(i == 0){
			grade[score[i].second] = 1;
			continue;
		}
		if(score[i].first == score[i-1].first){
			grade[score[i].second] = grade[score[i-1].second];
			continue;
		}
		grade[score[i].second] = i+1;
	}
	rep(i,n)cout<<grade[i]<<endl; 
	return 0;
}