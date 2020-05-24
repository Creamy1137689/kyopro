#include <iostream>
using namespace std;

int main(){
    int w,h,n;
    cin >> w >> h >> n;
    int cam[w][h] = {0};
    int x[n], y[n], a[n];
    for(int i=0; i<n; ++i){
        cin >> x[i] >> y[i] >> a[i];
    }
    for(int i=0; i<n; ++i){
        if(a[i] == 1){
            for(int j = 0; j < x[i]; ++j){
                for(int k = 0; k<h; ++k) cam[j][k] = 1;
            }
        }
        if(a[i] == 2){
            for(int j = x[i]; j<w; j++){
                for(int k = 0; k<h; ++k) cam[j][k] = 1;
            }
        }
        if(a[i] == 3){
            for(int j = 0; j<w; ++j){
                for(int k = 0; k<y[i]; k++) cam[j][k] = 1;
            }
        }
        if(a[i] == 4){
            for(int j = 0; j<w; ++j){
                for(int k = y[i]; k<h; ++k) cam[j][k] = 1;
            }
        }
    }
    int result = 0;
    for(int i = 0; i<w; ++i){
        for(int j = 0; j<h; ++j){
            if(cam[i][j] == 0) ++result;
        }
    }
    cout << result << endl; return 0;
}