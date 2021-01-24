#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int a[3*n];
    for(int i = 0; i<3*n; ++i){
        cin >> a[i];
    }
    sort(a,a+3*n); reverse(a,a+3*n);
    
    long long result = 0L;
    for(int i=0; i<2*n; ++i){
        if(i%2 == 1){ result += a[i];}
    }
    cout << result << endl; return 0;
}