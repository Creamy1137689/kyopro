#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int result = 0;
    for(int i = a; i<=b; ++i){
        if(i%10 == i/10000%10 && i/10%10 == i/1000%10) ++result;
    }
    cout << result << endl; return 0;
}