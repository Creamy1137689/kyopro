#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i= 0; i<n; ++i){
        cin >> a[i];
    }
    sort(a,a+n);
    int result = 0;
    for(; a[result] <= x && result < n-1; ++result){
        x -= a[result];
    }
    if(x == a[n-1]) ++result;
    cout << result << endl; return 0;
}