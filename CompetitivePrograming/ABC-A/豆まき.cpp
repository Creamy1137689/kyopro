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
    int a,b,c; cin >> a >> b>>c;
    int aa = 1,ab = 1,ac = 1;
    if(a<b)++aa; if(a<c) ++aa;
    if(b<a)++ab; if(b<c)++ab;
    if(c<a)++ac; if(c<b)++ac;
    cout << aa << endl << ab << endl << ac << endl; return 0;
}