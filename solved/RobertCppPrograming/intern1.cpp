#include <iostream>
using namespace std;

static int a = 3;

static void func(){
    cout << "a = " << a << endl;
}

void func2(){
    func();
}