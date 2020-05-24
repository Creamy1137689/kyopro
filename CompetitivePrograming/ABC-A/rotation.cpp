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
    string x,y; cin >> x >>y;
    if(x[0]==y[2]&&x[1]==y[2]&&x[2]==y[0])cout << "YES" << endl;
    else cout << "NO" << endl; return 0;
}
