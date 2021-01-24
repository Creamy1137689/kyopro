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

int N,a,b,c;

int look(char ch){
	if(ch == 'A'){
		return a;
	}else if(ch == 'B'){
		return b;
	}else{
		return c;
	}
}

void chval(char ch, int v){
	if(ch == 'A'){
		a += v;
	}else if(ch == 'B'){
		b += v;
	}else{
		c += v;
	}
	return ;
}

int main(){
	cin>>N>>a>>b>>c;
	vector<pair<char,char>> can(N);
	vector<char> ans(N);
	rep(i,N)cin>>can[i].first>>can[i].second;
	if(a+b+c == 0){cout<<"No"<<endl; return 0;}
	if(a+b+c == 1){
		rep(i,N){
			char x = can[i].first, y= can[i].second;
			if(look(x) == 0 && look(y) == 0){cout<<"No"<<endl; return 0;}
			if(look(x) == 1){ans[i] = y; chval(y,1); chval(x, -1);}
			else if(look(y) == 1){ans[i] = x; chval(x,1); chval(y, -1);}
		}
	}else{
		rep(i,N){
			char x = can[i].first, y = can[i].second;
			if(look(x) == 0 && look(y) == 0){cout<<"No"<<endl; return 0;}
			if(look(x) > look(y)){ans[i] = y; chval(y,1); chval(x, -1);}
			else if(look(y) > look(x)){ans[i] = x; chval(x,1); chval(y, -1);}
			else{
				if(i+1<N && (can[i+1].first == x || can[i+1].second == x)){
					ans[i] = x; chval(x,1); chval(y, -1);
				}else{
					ans[i] = y; chval(y,1); chval(x, -1);
				}
			}
			// printf("[%d] %d %d %d\n", i,a,b,c);
		}
	}
	cout<<"Yes"<<endl;
	show(ans);
	return 0;
}

// int main(){
// 	int N,a,b,c; cin>>N>>a>>b>>c;
// 	int score[3] = {0};
// 	int cnt[3] = {0};
// 	score[0] = a; score[1] = b; score[2] = c;
// 	vector<char> ans(N);
// 	vector<string> input(N);
// 	a = 0; b = 0; c = 0;
// 	rep(i,N){
// 		cin>>input[i];
// 		int a = input[i][0]-'A';
// 		int b = input[i][1]-'A';
// 		cnt[a]++; cnt[b]++;
// 	}
// 	int x,y;
// 	rep(i,N){
// 		x = input[i][0]-'A';
// 		y = input[i][1]-'A';
// 		if(score[x] == 0 && score[y] == 0){
// 			cout<<"No"<<endl; return 0;
// 		}
// 		if(score[x]>score[y]){
// 			score[x]--;
// 			score[y]++;
// 			ans[i] = (char)('A'+y);
// 		}
// 		if(score[x]<score[y]){
// 			score[x]++;
// 			score[y]--;
// 			ans[i] = (char)('A'+x);
// 		}
// 		if(score[x]==score[y]){
// 			if(cnt[x]>cnt[y]){
// 				score[x]++;
// 				score[y]--;
// 				ans[i] = (char)('A'+x);
// 			}else{
// 				score[x]--;
// 				score[y]++;
// 				ans[i] = (char)('A'+y);
// 			}
// 		}
// 		cnt[x]--; cnt[y]--;
// 	}
// 	cout<<"Yes"<<endl;
// 	show(ans);
// 	return 0;
// }