#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int l[n];
    for(int i = 0; i<n; ++i){
        cin >> l[i];
    }
    sort(l,l+n);
    int result = 0;
    for(int i = 1; i<=k; ++i){
        result += l[n-i];
    }
    cout << result << endl; return 0;
}