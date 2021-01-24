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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	string a, b;
	cin >> a >> b;
	set<char> cnt;
	bool same = false;
	rep(i,b.size()){
		if(cnt.count(b[i]) != 0)same = true;
		else cnt.insert(b[i]);
	}
	vector<bool> is_changed(b.size(), false);
	int ch_count = 0;
	rep(i,b.size()){
		if(a[i] != b[i]){
			for(int j = i + 1; j < b.size(); ++j){
				if(a[j] != b[j] && b[j] == a[i]){
					swap(b[i], b[j]);
					if(!(is_changed[i] && is_changed[j]))++ch_count;
					is_changed[i] = is_changed[j] = true;
					break;
				}
			}
		}
	}
	if(a != b)cout << "NO" << endl;
	else if(ch_count == 3 || ch_count == 1)cout << "YES" << endl;
	else if(ch_count <= 3 && same)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

