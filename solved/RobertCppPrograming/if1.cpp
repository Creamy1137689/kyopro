#include <iostream>
using namespace std;

void birthmonth(){ 
    int month;

    cout << "What month were you born? >> " << flush;
    cin >> month;

    if(1 <= month && month <= 12){
        cout << "How, " << month << " is!" << endl;
    }else{
        cout << "Hun, " << month << " !?" << endl << "There isn't such a month!!!" << endl;
    }
}

int main(){
    birthmonth();
    birthmonth();
}