#include <iostream>
using namespace std;

int main(){
    char hello[] = "Hello.";

    cout << "\"" << hello << "\" into the char code >> " << endl;

    for(int i = 0; i < (int)sizeof hello; ++i){
        cout << (int)(unsigned char)hello[i] << " , ";
    }

    cout << endl;
}