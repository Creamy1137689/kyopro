#include <iostream>
using namespace std;

int main(){
    for(;;){
        int a,b;
        cout << "Input 1st number. >> " << flush;
        cin >> a;

        cout << "Input 2nd number. >> " << flush;
        cin >> b;

        if(b == 0){
            cout << "You couldn't devide the number with 0." << endl;
            break;
        }

        cout << a << " / " << b << " = " << a/b << "...." << a%b << endl;
    }
    cout << "THe program has ended." << endl;
}