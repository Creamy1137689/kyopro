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

bool isOK(int a[], int index, int key){
    if(a[index] <= key) return true;
    else return false;
}

int binary_search(int a[], int nax, int key){
    int ng = 0;
    int ok = nax+1;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(a,mid,key))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	int N,Q,s,q,ans;
	cin>>N;
	int score[1000100] = {0};
	rep(i,N){
		cin>>s;
		++score[s];
	}
	for(int i = 1000010; i>= 0; --i){
		score[i] += score[i+1];
	}
	// rep(i,N+1)printf("[above score:%d -> %d]\n", i, score[i]);
	cin>>Q;
	rep(i,Q){
		cin>>q;
		ans = binary_search(score, 1000010, q);
		if(ans == 1)ans = 0;
		cout<<ans<<endl;
	}
	return 0;
}