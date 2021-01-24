#include <iostream>
using namespace std;

enum CompareResult {
    CR_LESS_THAN = 0,
    CR_MUCH_THAN = 1,
    CR_EQUAL_TO = 2,
};

CompareResult Compare(int a, int b){
    return 
    a < b ? CR_LESS_THAN : 
    a > b ? CR_MUCH_THAN : 
    CR_EQUAL_TO; 
}

bool Compare(){
    const char* massage[] = {
        "The former is smaller than the later.",
        "The former is bigger than the later.",
        "The former if equal to the later.",
    };

    int a,b;
    cout << "Put two numbers >> " << flush;
    cin >> a >> b;

    if(a == -1){ return false;}

    cout << massage[Compare(a,b)] << endl;

    return true;
}

int main(){
    while(Compare()){
    }
}