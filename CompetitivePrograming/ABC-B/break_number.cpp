#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i<7; ++i){
        if(n < pow(2,i)){ cout << pow(2,i-1) << endl; return 0;}
    }
    cout << "64" << endl; return 0;
}