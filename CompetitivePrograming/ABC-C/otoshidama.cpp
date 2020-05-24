#include <iostream>
using namespace std;


int main(){
    int n, y, a = 0, b = 0, c = 0;
    cin >> n >> y;
    for(; a+b+c <= n; ++a){
        b = 0;
        for(; a+b+c <= n; ++b){
            for(; a+b+c <= n; ++c){
                //cout << a << ' ' << b << ' ' << c << endl;
                if(a*10000+b*5000+c*1000 == y && a+b+c == n){
                    cout << a << ' ' << b << ' ' << c << endl;
                    return 0;
                }
            }
            c = 0;
        }
        b = 0;
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;
}