#include <iostream>
using namespace std;

int a = 0;

void inc(){
    int b = 0;
    ++a; ++b;
    cout << a << " <-a | b-> " << b << endl;
}

int main(){
    inc();
    inc();
    inc();
}