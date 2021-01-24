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

int main(){
	int K;
	cin>>K;
	vector<string> runrun(100010);
	queue<string> Q;
	int cnt = 0;
	REP(i,9){
		runrun[cnt++] = to_string(i);
		Q.push(to_string(i));
	}
	while(cnt<K){
		string s = Q.front();
		char last = s[s.size()-1];
		Q.pop();
		if(last == '0'){
			string n1 = s + '0';
			string n2 = s + '1';
			runrun[cnt++] = n1; runrun[cnt++] = n2;
			Q.push(n1); Q.push(n2);
		}else if(last =='9'){	
			string n1 = s + '8';
			string n2 = s + '9';
			runrun[cnt++] = n1; runrun[cnt++] = n2;
			Q.push(n1); Q.push(n2);
		}else{
			string n1 = s + (char)((int)last-1);
			string n2 = s + last;
			string n3 = s + (char)((int)last+1);
			runrun[cnt++] = n1;
			runrun[cnt++] = n2;
			runrun[cnt++] = n3;
			Q.push(n1); Q.push(n2); Q.push(n3);
		}
	}
	cout<<runrun[K-1]<<endl;
	return 0;
}