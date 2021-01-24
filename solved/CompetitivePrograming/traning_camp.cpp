#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

const int long long st = 1000000007;

int main(){
    int n; cin >> n;
    long long ans = 1;
    for(int i = 1; i<=n; ++i){
        ans = ans*i%st;
    }
    cout << ans << endl; return 0;
}