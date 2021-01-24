#include <iostream>
using namespace std;

int main(){
    int a, b, dis, result;
    while(true){
        cout << "Input 1st number. >> " << flush;
        cin >> a;

        cout << "Input 2nd number. >> " << flush;
        cin >> b;

        cout << "Choice type of disposal." << endl << "1. Addition  2. Subtraction" << endl << "3. Multiplication  4. Division >> " << flush;
        cin >> dis;

        switch (dis)
        {
        case 1:
            result = a+b; break;
        case 2:
            result = a-b; break;
        case 3:
            result = a*b; break;
        case 4:
            result = a/b; break;
        default:
            cout << "Nesty!!" << endl << endl;
            continue;
        }

        cout << "The answer is " << result << '.' << endl << endl;
    }
}