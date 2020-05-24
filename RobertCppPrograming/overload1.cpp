#include <iostream>
using namespace std;

int Abs(int a){
    if(a < 0){
        return -a;
    }else{
        return a;
    }
}

double Abs(double a){
    if(a < 0){
        return -a;
    }else{
        return a;
    }
}

int input(int& i, double& d){
    cout << "put integer number >> " << flush;
    cin >> i;
    if(i == 0) return 0;

    cout << "put decimal number >> " << flush;
    cin >> d;
    if(d == 0) return 0;

    return 1;
}

void showabs(int i, double d){
    printf("Abs(%d) = %d\n", i, Abs(i));
    printf("Abs(%f) = %f\n", d, Abs(d));
}

int main(){
    int i; double d;
    while(input(i,d)){
        showabs(i,d);
    }
}