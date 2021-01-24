#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int binary[2] = {0}; for(int i = 0; i<n; ++i){
        int tmp; cin >> tmp;
        (tmp%2) ? ++binary[1] : ++binary[0];
    }
    cout << ((binary[1]%2) ? "NO" : "YES") << endl; return 0;
}