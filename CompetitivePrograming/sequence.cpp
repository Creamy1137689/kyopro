#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int ch_sign(int n){
    if(n == 0)return 0;
    return (n>0)-(n<0);
}

int main(){
    int n; cin >> n;
    int a[n]; for(int i = 0; i<n; ++i) cin >> a[i];

    int sign1 = 1, sign2 = -1;
    long long s1 = 0, s2 = 0;
    long long ans1 = 0, ans2 = 0;
    for(int i = 0; i<n; ++i){
        //cout << a[i] << ',' <<  s << ',' << sign << endl;
        //while(abs(a[i]) <= abs(s)){ ++ans; a[i] -= sign;}
        //int dis = abs(s) - abs(a[i]) + 1;
        //cout << dis << endl << endl;
        //if(dis > 0){ans += dis; a[i] -= sign*dis;}
        //s += a[i]; sign *= -1;

        s1 += a[i]; s2 += a[i]; sign1 *= -1; sign2 *= -1;
        if(ch_sign(s1) != sign1){ ans1 += abs(s1)+1; s1 = sign1;}
        if(ch_sign(s2) != sign2){ ans2 += abs(s2)+1; s2 = sign2;}
    }
    cout << min(ans1,ans2) << endl; return 0;
}