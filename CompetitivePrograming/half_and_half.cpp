#include <iostream>
using namespace std;

int another(){
    long long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    long long result = 100000000;
    for(long long i = 0; i<=max(x,y); ++i){
        result = min(result, c*2*i+a*max(0L,x-i)+b*max(0L,y-i));
    }

    cout << result << endl; return 0;
}

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int for_a, for_b, for_ab;
    if(a<2*c) for_a = a; else for_a = 2*c;
    if(b<2*c) for_b = b; else for_b = 2*c;
    if(a+b<2*c) for_ab = a+b; else for_ab = 2*c;

    int tmp = min(x, y), result = 0;
    result += tmp*for_ab; x -= tmp; y -= tmp;
    result += x*for_a; result += y*for_b;

    cout << result << endl; return 0;
}

