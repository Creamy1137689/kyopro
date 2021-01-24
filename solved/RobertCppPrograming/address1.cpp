#include <iostream>
using namespace std;

void foo(){
    int a;
    char b[10];
    cout << "a   : " << (size_t)&a << endl
        << "b   : " << (size_t)b << endl
        << "foo : " << (size_t)foo << endl;
}

int main(){
    foo();
}