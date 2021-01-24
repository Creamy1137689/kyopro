#include <iostream>
using namespace std;

extern int a;
void func();

int main(){
    func();
    a = 6;
    func();
}