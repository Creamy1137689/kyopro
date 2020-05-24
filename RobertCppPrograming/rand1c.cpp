#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initrand(){
    srand((unsigned int)time(NULL));
}

int dice(){
    return rand()%6 + 1;
}

int main(){
    initrand();
    for(int i = 0; i <20; ++i){
        cout << dice() + dice() << ' ';
    }
    cout << endl;
}