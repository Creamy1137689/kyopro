#include <iostream>
using namespace std;

void showCode(char ch){
    cout << "the assinment of \'"<< ch << "\' >> "<< (int)(unsigned char)ch << endl; 
}

int main(){
    showCode('0');
    showCode('A');
}