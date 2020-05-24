#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m = n;
    int fx = 0;
    while(m > 0){
        fx += m%10;
        m /= 10;
    }
    string rs;
    if(n%fx == 0) rs = "Yes";
    else rs = "No";
    cout << rs << endl; return 0;
}