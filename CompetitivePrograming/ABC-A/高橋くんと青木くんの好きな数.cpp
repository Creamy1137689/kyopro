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
    int a,b,n; cin >>a >>b>>n;
    if(a<b){int tmp = a; a= b; b=tmp;}
    int t_a = a, t_b = b;
    while(t_a%t_b != 0){
        int tmp = t_a%t_b; t_a = t_b; t_b = tmp;
    }
    int ans = a*b/t_b;
    for(int i=2; ans<n; ++i)ans = ans/(i-1)*i;
    cout << ans << endl; return 0;
}
