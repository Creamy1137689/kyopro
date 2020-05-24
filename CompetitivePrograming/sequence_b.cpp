#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    long long array[n]; for(int i = 0; i<n; ++i)cin >> array[i];
    long long min1 = 0;
    long long sum1 = 0;
    for(int i = 0; i<n; ++i){
        sum1 += array[i];
        if(i%2 == 0){
            if(sum1 <= 0){
                min1 += abs(sum1)+1;
                sum1 = 1;
            }
        }else{
            if(sum1 >= 0){
                min1 += abs(sum1)+1;
                sum1 = -1;
            }
        }
    }
    long long  min2 = 0;
    long long sum2 = 0;
    for(int i = 0; i<n; ++i){
        sum2 += array[i];
        if(i%2 == 1){
            if(sum2 <= 0){
                min2 += abs(sum2)+1;
                sum2 = 1;
            }
        }else{
            if(sum2 >= 0){
                min2 += abs(sum2)+1;
                sum2 = -1;
            }
        }
    }
    cout << min(min1, min2) << endl; return 0;
}