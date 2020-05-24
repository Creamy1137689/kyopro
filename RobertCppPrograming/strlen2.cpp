#include <iostream>
using namespace std;

size_t strlen(char* str){
    char* p;
    for(p = str; *p != '\0'; ++p){}
    return p-str;
}

void showlength(char* str){
    cout << "\"" << str << "\"is " << strlen(str) << " bytes." << endl;
}

int main(){
    showlength("Hello");
    showlength("");
}