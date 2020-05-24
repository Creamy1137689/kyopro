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
    int n; cin >> n;
    vector <int> array; int m = 0;
    if(n>=8){array.push_back(8); n -= 8; ++m;}
    if(n>=4){array.push_back(4); n -= 4; ++m;}
    if(n>=2){array.push_back(2); n -= 2; ++m;}
    if(n>=1){array.push_back(1); n -= 1; ++m;} 
    cout << m << endl; 
    for(auto c : array)cout << c << endl;
    return 0;
}