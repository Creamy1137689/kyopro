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
    string a,b,c; cin >> a >> b >> c;
    cout << ((a[a.size()-1] == b[0] && b[b.size()-1] == c[0])?"YES":"NO") <<endl; return 0;
}
