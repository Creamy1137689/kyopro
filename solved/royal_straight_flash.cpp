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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	char type[4] = {'S', 'H', 'D', 'C'};
	string s;
	cin>>s;
	vector<pair<char,int>> input;
	vector<pair<char,int>> ans;
	int now_len = inf;
	rep(i,s.size()){
		pair<char,int> t;
		t.first = s[i++];
		if(s[i] == 'A')t.second = 1;
		else if(s[i] == 'J')t.second = 11;
		else if(s[i] == 'Q')t.second = 12;
		else if(s[i] == 'K')t.second = 13;
		else if(s[i] == '1'){
			t.second = 10;
			++i;
		}else{
			t.second = s[i]-'0';
		}
		input.push_back(t);
	}
	rep(k,4){
		char n_type = type[k];
		int now = 0;
		vector<pair<char,int>> e_ans;
		for(auto x: input){
			if(x.first == n_type && ((10 <= x.second && x.second <= 13) || x.second == 1)){
				++now;
			}else{
				e_ans.push_back(x);
			}
			if(now == 5){
				if(e_ans.size() < now_len){
					ans = e_ans;
					now_len = e_ans.size();
				}
				break;
			}
		}
	}
	if(ans.size() == 0){
		cout<<0;
	}
	for(auto x: ans){
		char tp = x.first;
		string num;
		int t = x.second;
		if(t == 1)num = "A";
		else if(t == 11)num = "J";
		else if(t == 12)num = "Q";
		else if(t == 13)num = "K";
		else num = to_string(t);
		cout<<tp<<num;
	}
	cout<<endl;
	return 0;
}