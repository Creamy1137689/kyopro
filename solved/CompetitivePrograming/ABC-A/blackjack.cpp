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
    string s; cin >> s;
    if(s == "SUN") cout << 7 << endl;
    else if(s == "MON") cout << 6 << endl;
    else if(s == "TUE") cout << 5 << endl;
    else if(s == "WED") cout << 4 << endl;
    else if(s == "THU") cout << 3 << endl;
    else if(s == "FRI") cout << 2 << endl;
    else if(s == "SAT") cout << 1 << endl; return 0;
}
