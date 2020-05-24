#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const double TRIAL_COUNT = 1000000000.0;
const int PEOPLE = 10000;
const int TIME_SECT = 14;
const int LINE = 100;

void init_times(int times[]){
    for(int i = 0; i < TIME_SECT; ++i){
        times[i] = 0;
    }
}

bool check_result(int times[]){
    for(int i = 0; i < TIME_SECT; ++i){
        if(times[i] < LINE){ return true; }
    }
    return false;
}

int trial(){
    int a = rand()%14;
    return a;
}


int main(){
    srand((unsigned int)time(NULL));
    int times[TIME_SECT];
    double result = 0.0;
    int m;
    for(int i = 0; i < TRIAL_COUNT; ++i){
        init_times(times);
        for(int j = 0; j < PEOPLE; ++j){
            ++(times[trial()]);
        }
       
        if(check_result(times)){ ++result; }
    }
    cout << "The probability is " << (result / TRIAL_COUNT) << endl;
    cout << "The result is " << result <<endl;
}


/*
if((i%100) == 0){
    for(int x = 0; x < TIME_SECT; ++x){
        cout << times[x] << ' ';
    }
    cout << endl;
}
*/