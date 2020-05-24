#include <iostream>
#include <cstdlib>
using namespace std;

int dice(){
    return (int)(rand()/(RAND_MAX+1.0)*6) + 1;
}

int main(){
    for(int i = 0; i < 20; ++i){
        cout << dice() + dice() << ' ';
    }
    cout << endl;
}