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
    if(a[index] >= key) return true;
    else return false;
}

int binary_search(int a[], int nax, int key){
    int ng = -1;
    int ok =nax;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(a,mid,key))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	int N,M; cin>>N>>M;
	int child[1000000] = {0};
	rep(i,M){
		int sushi; cin>>sushi;
		if(sushi <= child[0]){cout<<-1<<endl; continue;}
		int eater = binary_search(child, N, sushi);
		child[eater-1] = sushi;
		// cout<<line<<endl;
		// show(child);
		// cout<<eater<<endl;
		// cout<<N+1-eater<<endl;
		// cout<<line<<endl;
		cout<<N+1-eater<<endl;
	}
	return 0;
}