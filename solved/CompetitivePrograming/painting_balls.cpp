#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    long long n,k; cin >> n >> k;
    long long ans = k;
    ans *= pow(k-1L,n-1L);
    cout << ans << endl; return 0;
}