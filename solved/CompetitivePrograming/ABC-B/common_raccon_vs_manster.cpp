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
    int h,n; cin>>h>>n;
    ll m_dam = 0; rep(i,n){int tmp; cin >>tmp; m_dam+=tmp;}
    cout<<((m_dam>=h)?"Yes":"No")<<endl;return 0;
}
