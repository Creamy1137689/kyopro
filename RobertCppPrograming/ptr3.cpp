#include <iostream>
using namespace std;

int main(){
    int n[4];
    int* p = n;

    cout << "p   : " << (size_t)p << endl << "&n[0]   : " << (size_t)&n[0] << endl;

    p += 2;
    cout << "p   : " << (size_t)p << endl << "&n[2]   : " << (size_t)&n[2] << endl;

    cout << "p - &n[0] : " << (size_t)(p - &n[0]) <<endl;

    //impossible
    //cout << "p + &n[1] : " << (size_t)(p + &n[1]) << endl;
}