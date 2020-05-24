#include <iostream>
using namespace std;

int pow(int a, int b){
    int result = 1;
    for(int i = 0; i < b; ++i){
        result *= a;
    }
    return result;
}

int main(){
    int a, result = 0;
    cin >> a;
    
    for(int i = 1; i <= 3; ++i){
        if(a % pow(10,i) >= pow(10, (i-1))){ ++result; }
    }
    cout << result << endl;
    return 0;
}

