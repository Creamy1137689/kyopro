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
    int array[11] = {0};rep(i,3){
        int tmp; cin>>tmp;
        array[tmp]++;
    }
    cout << ((array[5] == 2&&array[7]==1)?"YES":"NO")<<endl; return 0;
}