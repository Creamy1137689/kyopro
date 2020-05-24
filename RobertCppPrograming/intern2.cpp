#include <iostream>
using namespace std;

static int a = 6;

void func(){
    cout << "a = " << a << endl;
}

void func2();

int main(){
    func();
    func2();
    a = 8;
    func();
    func2();
}