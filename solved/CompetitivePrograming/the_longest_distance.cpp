#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int x[n], y[n];
    for(int i=0; i<n; ++i){
        cin >> x[i] >> y[i];
    }

    double max = 0;
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            double tmp = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
            if( tmp > max ) {max = tmp;}
        }
    }
    cout << max << endl; return 0;
}