#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int time[101] = {0};
    int ans = 0;
    for(int i = a; i < b; ++i)time[i] = 1;
    for(int i = c; i < d; ++i)if(time[i])++ans;
    cout << ans << endl; return 0;
}