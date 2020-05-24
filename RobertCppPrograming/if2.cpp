#include <iostream>
using namespace std;

void divide(){
    int a,b;
    cout << "Input devidee number >> " << flush;
    cin >> a;
    cout << "Input devider number >> " << flush;
    cin >> b;

    if(b == 0){
        cout << "You couldn't devide number with 0." << endl;
    }else{
        cout << a << " / " << b << " = " << a/b << "..." << a%b << endl;
    }
}

int main(){
    divide();
    divide();
}