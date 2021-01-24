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

// bool isOK(int a[], int index, int key){
//     if(a[index] >= key) return true;
//     else return false;
// }

// int binary_search(int a[], int nax, int key){
//     int ng = -1;
//     int ok =nax;
//     while(abs(ok-ng) > 1){
//         int mid = (ok + ng)/2;
//         if(isOK(a,mid,key))ok = mid;
//         else ng = mid;
//     }
//     return ok;
// }

// int main(){
// 	int N,M; cin>>N>>M;
// 	int room[100100];
// 	vector<int> query(M);
// 	bool al[100100] = {0};
// 	rep(i,N)cin>>room[i];
// 	rep(i,M)cin>>query[i];
// 	sort(room, room+N);
// 	rep(i,N)cout<<room[i]<<' ';
// 	cout<<endl;
// 	rep(i,M){
// 		int id = binary_search(room, N, query[i]);
// 		cout<<id<<endl;
// 		if(id == N){
// 			cout<<"NO"<<endl;
// 			return 0;
// 		} else {
// 			al[id] = true;
// 		}
// 	}
// 	cout<<"YES"<<endl;
// 	return 0;
// }

int main(){
	int N,M; cin>>N>>M;
	if(N<M){cout<<"NO"<<endl; return 0;}
	vector<int> room(N);
	vector<int> query(M);
	rep(i,N)cin>>room[i];
	rep(i,M)cin>>query[i];
	sort(all(room));
	sort(all(query));
	bool ans = true;
	REP(i,M){
		if(room[N-i]<query[M-i]){
			ans = false;
			break;
		}
	}
	// rep(i,N){
	// 	int t; cin>>t;
	// 	room[t]++;
	// }
	// rep(i,M){
	// 	int t; cin>>t;
	// 	query[t]++;
	// }
	// // rep(i,100099)room[i+1] = room[i+1] + room[i];
	// for(int i = N-2; i>=0; --i)room[i] = room[i] + room[i+1];
	// bool ok = true;
	// // for(int i = N-2) 
	// rep(i,100100)if(room[i]<query[i]){
	// 	ok = false;
	// 	break;
	// }
	cout<<((ans)?"YES":"NO")<<endl;
}