#include <iostream>
using namespace std;

bool Isdigit(char ch){
    return '0' <= ch && ch <= '9';
}

int main(){
    while(true){
        char ch;
        cout << "put a number >> " << flush;
        cin >> ch;
        if(ch == 'q' || ch == 'Q') break;

        if(Isdigit(ch)){
            cout << "That is the very nunber" << endl;
        }else{
            cout << "That is not a number" << endl;
        }
    }

    cout << "Bye...." << endl;
}