#include <iostream>
using namespace std;

void changetoshowa(int &western){
    if(1926 <= western && western <= 1989){
        western -= 1925;
    }else{
        western = 0;
    }
}

void showa(){
    int year;
    cout << "Input western number. >>" << flush;
    cin >> year;

    changetoshowa(year);
    if(year == 0){
        cout << "It is not showa." << endl;
    }else{
        cout << "That is <S" << year << ">." << endl;
    }
}

int main(){
    showa();
    showa();
}