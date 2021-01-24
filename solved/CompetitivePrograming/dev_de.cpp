#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    const int MAX_N = 100;
    vector <int> primes (MAX_N+1,1);
    primes[0] = 0; primes[1] = 0;
    for(int i = 2; i<=MAX_N; ++i){
        if(primes[i] == 1){
            int k = 2;
            while(k*i <= 100){primes[k*i] = 0; k++;}
        }
    }
    int n; cin >> n;
    int ans = 0;
    rep(i,n){
        int tmp; cin >> tmp;
        if(primes[tmp])++ans;
    }
    cout << ((ans%2) ? "Yes" : "No") << endl; return 0;

}
