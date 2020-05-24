#include <iostream>
using namespace std;

int result = 0;

int check(int n, int *a){
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0){ a[i] = a[i]/2; }else{ return 0;}
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    int result = 0;
    while(check(n,a)){ ++result; }
    
    cout << result << endl;
    return 0;
}