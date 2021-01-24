#include <iostream>
using namespace std;

int sum_digit(int m){
    int sum = 0;
    while(m){
        sum += m % 10;
        m = m / 10;
    }
    return sum;
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;

    int result = 0;
    int tmp;
    for(int i = 1; i <= n; ++i){
        tmp = sum_digit(i);
        //cout << tmp << ' ' ;
        if (a <= tmp && tmp <= b) result += i;
    }

    cout  << endl << result << endl;
    return 0;
}