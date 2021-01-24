#include <iostream>
using namespace std;

int change_into_showa(int western){
    if(1926 <= western && western <= 1989){
        return western-1925;
    }else{
        return 0;
    }
}

int main(){
    int year;
    cout << "Input western number. >>" << flush;
    cin >> year;
    
    year = change_into_showa(year);
    if(year == 0){
        cout << "That year is not showa." << endl;
    }else{
        cout << "That year is S" << year << "." << endl;
    }
}