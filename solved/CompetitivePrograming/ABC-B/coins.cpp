#include <iostream>
using namespace std;

int main(){
    int a,b,c,x;
    cin >> a >> b >> c >> x;

    if(a*500 > x) a = x / 500 + 1;
    if(b*100 > x) b = x / 100 + 1;
    if(c*50 > x) c = x / 50 + 1;

    int result = 0;
    for(int ai = 0; ai <= a; ++ai){
        for(int bi = 0; bi <= b; ++bi){
            for(int ci = 0; ci <= c; ++ci){
                if(500*ai + 100*bi + 50*ci == x) ++result;
            }
        }
    }

    cout << result << endl;
    return 0;
}

/*
#include <iostream>
using namespace std;

int result = 0;

int solve(int a, int b, int c, int x){
    if(x == 0){ ++result; return 0;}
    if(x < 500){ a = 0; }
    if(x < 100){ b = 0; }
    if(x < 500){ c = 0; }
    if(a*500 + b*100 + c*50 <= x) return 0;

    if(x >= 500){ solve(a-1, b, c, x-500); }
    if(x >= 100){ solve(a, b-1, c, x-100); }
    solve(a, b, c-1, x-50);

    return 0;
}

int main(){
    int a,b,c,x;
    cin >> a >> b >> c >> x;

    solve(a,b,c,x);

    cout << result << endl;
    return 0;
}
*/