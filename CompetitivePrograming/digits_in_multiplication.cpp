#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n; cin >> n;
    for(long long i = (long long)sqrt(n); i>0LL; --i){
        if(n%i == 0LL){cout << (int)max(log10(i)+1LL, log10(n/i)+1LL) << endl; return 0;}
    }
}