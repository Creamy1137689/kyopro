#include <iostream>
using namespace std;

int main(){
    int a,b,c; cin >> a >> b >> c;
    int sum = a + b + c;
    int ideal = sum;
    int parity = sum%2;
    while(ideal%3 != 0 || ideal/3 < max(a,max(b,c)) || ideal%2 != parity) ++ideal;
    cout << (ideal-sum)/2 << endl; return 0;
}