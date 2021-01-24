#include <iostream>
using namespace std;

int main(){
    int n,a;
    cin >> n >> a;

    n %= 500;
    if(n <= a){ cout << "Yes" << endl; return 0;}
    cout << "No" <<endl;
    return 0;
}