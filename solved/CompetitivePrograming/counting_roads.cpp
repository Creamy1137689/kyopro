#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n] = {0};
    for(int i=0; i<2*m; ++i){
        int tmp; cin >> tmp;
        ++a[tmp-1];
    }
    for(int i=0; i<n; ++i){
        cout << a[i] << endl;
    }
    return 0;
}