#include <iostream>
using namespace std;

size_t strlen(char* str){
    int i;
    for(i = 0; *(str+i) != '\0'; ++i){}
    return i;
}

void showlength(char* str){
    cout << "\"" << str << "\"is " << strlen(str) << " bytes." << endl;
}

int main(){
    showlength("Hello");
    showlength("");
}