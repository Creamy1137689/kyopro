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
    int x,a,b; cin >> x >> a >> b;
    if(b<=a)cout << "delicious" << endl;
    else if(b-a<=x)cout << "safe" << endl;
    else cout << "dangerous" <<endl; 
    return 0;
}
