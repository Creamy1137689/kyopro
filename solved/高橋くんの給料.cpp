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

struct person{
	int buka_max = 0;
	int buka_min = inf;
};

int main(){
	int N;
	cin>>N;
	vector<int> buka(N+1,0);
	vector<person> people(N+1);
	vector<int> boss(N+1,inf);
	for(int i = 2; i<=N; ++i){
		cin>>boss[i];
		buka[boss[i]]++;
	}
	bool rest = true;
	// REP(i,N)cout<<boss[i]<<' ';
	// cout<<endl;
	// REP(i,N)cout<<buka[i]<<' ';
	// cout<<endl;
	while(rest){
		rest = false;
		for(int i = 2; i<=N; ++i){
			if(buka[i] == -1)continue;
			if(buka[i] != 0){rest = true; continue;}
			int my_salary = ((people[i].buka_min==inf)?0:people[i].buka_min) + people[i].buka_max + 1;
			buka[boss[i]]--;
			buka[i] = -1;
			people[boss[i]].buka_max = max(people[boss[i]].buka_max, my_salary);
			people[boss[i]].buka_min = min(people[boss[i]].buka_min, my_salary);
		}
		// REP(i,N){
		// 	cout<<people[i].buka_max<<' '<<people[i].buka_min<<endl;
		// }
		// REP(i,N)cout<<buka[i]<<' ';
		// cout<<endl;
	}
	// REP(i,N){
	// 	cout<<people[i].buka_max<<' '<<people[i].buka_min<<endl;
	// }
	cout<<((people[1].buka_min==inf)?0:people[1].buka_min) + people[1].buka_max + 1<<endl;
	return 0;
}