#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5;

void init(int array[]){
    for(int i = 0; i < ARRAY_SIZE; ++i){
        array[i] = i*5;
    }
}

void show(const int array[]){
    for(int i = 0; i < ARRAY_SIZE; ++i){
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main(){
    int n[ARRAY_SIZE];
    
    init(n);
    show(n);
}