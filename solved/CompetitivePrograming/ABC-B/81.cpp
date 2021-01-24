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
    int n;;cin>>n;
    for(int i = 1; i<10; ++i){
        if(n%i==0&&n/i<10){cout<<"Yes"<<endl; return 0;}
    }
    cout<<"No"<<endl;return 0;
}
