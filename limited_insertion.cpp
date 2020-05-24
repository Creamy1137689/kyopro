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

int main(){
	int N; cin>>N;
	vector<int> b(N);
	rep(i,N)cin>>b[i];
	vector<int> ans;
	rep(_,N){
		bool ok = false;
		for(int j = b.size()-1; j>=0; --j){
			// printf("[i,j] = [%d, %d]\n",i,j);
			if(b[j] == j+1){
				// printf("[i,j] = [%d, %d]\n",_,j);
				ok = true;
				ans.push_back(b[j]);
				b.erase(b.begin() + j);
				break;
			}
		}
		if(!ok){cout<<-1<<endl; return 0;}
	}
	reverse(all(ans));
	show(ans);
}

// vector<int> a;

// int shorter(int n){
// 	if(n>a.size())return 0;
// 	int res = 0;
// 	for(int i = n-1; i<a.size(); ++i){
// 		if(a[i] <= n) ++res;
// 	}
// 	return res;
// }

// int main(){
// 	int N; cin>>N;
// 	vector<int> b(N);
// 	rep(i,N)cin>>b[i];
// 	// is possible
// 	bool ok = true;
// 	rep(i,N)if(b[i] > i+1)ok = false;
// 	if(!ok){cout<<-1<<endl; return 0;}

// 	//way
// 	vector<int> need(N,0);
// 	rep(i,N){
// 		int cnt = 0;
// 		for(int j = i+1; j<N; ++j){
// 			if(b[j]<=b[i]) ++cnt;
// 		}
// 		need[i] = cnt;
// 	}
// 	map<int,int> rest;
// 	vector<int> ans;
// 	a.push_back(1);
// 	ans.push_back(1);
// 	for(int i = N-1; i>0; --i){
// 		if(b[i] <= a.size()+1 && need[i] <= shorter(b[i])){
// 			a.insert(a.begin()+b[i]-1, b[i]);
// 			ans.push_back(b[i]);
// 		}else{
// 			rest[rest.size()]  = i;
// 		}
// 		for(auto ele : rest){
// 			int x = ele.second;
// 			if(b[x] <= a.size()+1 && need[x] <= shorter(b[x])){
// 				a.insert(a.begin()+b[x]-1,b[x]);
// 				ans.push_back(b[x]);
// 				rest.erase(ele.first);
// 			}
// 		}
// 	}
// 	while(ans.size() != N){
// 		for(auto ele : rest){
// 			int x = ele.second;
// 			if(b[x] <= a.size()+1 && need[x] <= shorter(b[x])){
// 				a.insert(a.begin()+b[x]-1,b[x]);
// 				ans.push_back(b[x]);
// 				rest.erase(ele.first);
// 			}
// 		}
// 	}
// 	show(ans);
// 	return 0;
// }

// vector<int> a;
// vector<int> ans;

// int shorter(int n){
// 	if(n>a.size())return 0;
// 	int res = 0;
// 	for(int i = n-1; i<a.size(); ++i){
// 		if(a[i] <= n) ++res;
// 	}
// 	return res;
// }

// int solve(int N){
// 	vector<int> b(N);
// 	srand(time(nullptr));
// 	rep(i,N){
// 		b[i] = rand()%(i+1)+1;
// 	}
// 	cout<<line<<endl;
// 	show(b);
// 	cout<<line<<endl;
// 	// is possible
// 	bool ok = true;
// 	rep(i,N)if(b[i] > i+1)ok = false;
// 	if(!ok){cout<<-1<<endl; return 0;}

// 	//way
// 	vector<int> need(N,0);
// 	rep(i,N){
// 		int cnt = 0;
// 		for(int j = i+1; j<N; ++j){
// 			if(b[j]<=b[i]) ++cnt;
// 		}
// 		need[i] = cnt;
// 	}
// 	map<int,int> rest;
// 	a.push_back(1);
// 	ans.push_back(1);
// 	for(int i = N-1; i>0; --i){
// 		if(b[i] <= a.size()+1 && need[i] <= shorter(b[i])){
// 			a.insert(a.begin()+b[i]-1, b[i]);
// 			ans.push_back(b[i]);
// 		}else{
// 			rest[rest.size()]  = i;
// 		}
// 		for(auto ele : rest){
// 			int x = ele.second;
// 			if(b[x] <= a.size()+1 && need[x] <= shorter(b[x])){
// 				a.insert(a.begin()+b[x]-1,b[x]);
// 				ans.push_back(b[x]);
// 				rest.erase(ele.first);
// 			}
// 		}
// 		cout<<line<<endl;
// 		show(a);
// 		cout<<line<<endl;
// 	}
// 	while(ans.size() != N){
// 		for(auto ele : rest){
// 			int x = ele.second;
// 			if(b[x] <= a.size()+1 && need[x] <= shorter(b[x])){
// 				a.insert(a.begin()+b[x]-1,b[x]);
// 				ans.push_back(b[x]);
// 				rest.erase(ele.first);
// 			}
// 		}
// 	}
// 	cout<<"ANS -> "; show(ans);
// 	cout<<"solve_end"<<endl<<endl;
// 	return 0;
// }

// int main(){
// 	int N; cin>>N;
// 	solve(N);
// 	vector<int> p;
// 	rep(i,N){
// 		int t = ans[i];
// 		p.insert(p.begin()+(t-1),t);
// 	}
// 	show(p);
// }

// int main(){
// 	int N; cin>>N;
// 	vector<int> b(N);
// 	rep(i,N)cin>>b[i];
// 	bool ok = true;
// 	rep(i,N)if(b[i] > i+1)ok = false;
// 	if(!ok){cout<<-1<<endl; return 0;}
// 	vector<int> need(N,0);
// 	rep(i,N){
// 		int cnt = 0;
// 		for(int j = i+1; j<N; ++j){
// 			if(b[i] >= b[j])++cnt;
// 		}
// 		need[i] = cnt;
// 	}
// 	stack<int> Q;
// 	vector<int> a;
// 	vector<int> ans;
// 	ans.push_back(1);
// 	a.push_back(1);
// 	for(int i = N-1; i>0; --i){
// 		// cout<<line<<endl;
// 		if((a.size() >= b[i]-1) && (a.size()-(b[i]-1) >= need[i])){
// 			a.insert(a.begin()+b[i]-1, b[i]);
// 			ans.push_back(b[i]);
// 		}else{
// 			// cout<<"in with "<<i<<endl;
// 			Q.push(i);
// 		}
// 		// cout<<Q.top()<<endl;
// 		if(!Q.empty()){
// 			int t = Q.top();
// 			if(a.size() >= b[t] && a.size()-(b[t]-1) >= need[t]){
// 				a.insert(a.begin()+b[t]-1, b[t]);
// 				ans.push_back(b[t]);
// 				Q.pop();
// 			}
// 		}
// 		// show(a);
// 	}
// 	while(!Q.empty()){
// 		int t = Q.top();
// 		Q.pop();
// 		a.insert(a.begin()+b[t]-1, b[t]);
// 		ans.push_back(b[t]);
// 	}
// 	show(ans);
// 	return 0;
// }