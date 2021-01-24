#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INTARRAY_SIZE = 100;

class IntArray{
private:
    int _array[INTARRAY_SIZE];

public:
    IntArray();
    void Set(int i, int num);
    int Get(int i);
private:
    void CheckIndex(int i);
};

IntArray::IntArray(){
    fill_n(_array, INTARRAY_SIZE, 0);
}

void IntArray::Set(int i, int num){
    CheckIndex(i);
    _array[i] = num;
}

int IntArray::Get(int i){
    CheckIndex(i);
    return _array[i];
}

void IntArray::CheckIndex(int i){
    if(i < 0 || INTARRAY_SIZE-1 < i){
        cout << "The index is not available!!" << endl;
        exit(EXIT_FAILURE);
    }
}

int main(){
    IntArray b;
    IntArray *ia = &b;
    int a;
    cin >> a ;
    for(int i = 5; i > -1; --i){
        ia->Set(i,a);
        cout << ia->Get(i) << endl;
    }
    cout << "fase 3";
    ia->Set(3,14);
    for(int i = 0; i < 6; ++i){
        cout << ia->Get(i) << endl;
    }
}