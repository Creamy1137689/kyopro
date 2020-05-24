#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int d = 0; 7*d <= n; ++d){
        if((n-7*d)%4 == 0){ cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl; return 0;
}