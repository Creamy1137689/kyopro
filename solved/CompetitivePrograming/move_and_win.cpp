#include <iostream>
using namespace std;

int main(){
    int n, a, b; cin >> n >> a >> b;
    cout << (((abs(a-b)-1)%2) ? "Alice" : "Borys") << endl; return 0;
}