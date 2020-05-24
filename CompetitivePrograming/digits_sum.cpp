#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int min = 1000000;
    for(int i = 1; i<= n/2; ++i){
        int p = i, q = n-i, s = 0;
        while(p > 0){
            s += p%10; p /= 10;
        }
        while(q > 0){
            s += q%10; q /= 10; 
        }
        if(s < min) min = s;
    }
    cout << min << endl; return 0;
}