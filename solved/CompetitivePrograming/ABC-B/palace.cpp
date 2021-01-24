#include <iostream>
#include <cmath>
using namespace std;

int n, a;
double t;

double dif(double tmp){
    return abs(tmp-a);
}

int main(){
    cin >> n >> t >> a;
    double h[n];
    for(int i=0; i<n; ++i){
        cin >> h[i];
    }
    double min_dif = dif(t-h[0]*0.006), min_index = 0;
    for(int i = 1; i<n; ++i){
        if( dif(t-h[i]*0.006) < min_dif ) { min_dif = dif(t-h[i]*0.006); min_index = i;}
    }
    cout << min_index + 1 << endl; return 0;
}