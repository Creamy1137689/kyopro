#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int m[n];
    for(int i = 0; i<n; ++i){
        cin >> m[i]; x -= m[i];
    }
    sort(m, m+n);
    int result = n;
    for(; x >= m[0]; ){
        x -= m[0]; ++result;
    }
    cout << result <<endl; return 0;
}