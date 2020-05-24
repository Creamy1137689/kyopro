#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    long long array[n]; for(int i = 0; i<n; ++i)cin >> array[i];
    int ans = 0;
    for(int i = 0; i<n; ++i){
        while(array[i+1] == array[i] && i<n) ++i;
        if(array[i+1] > array[i] && i<n) while(array[i+1] >= array[i] && i<n) ++i;
        else while(array[i+1] <= array[i] && i<n) ++i;
        ++ans;
    }
    cout << ans << endl; return 0;
}

/*
int main(){
    int n; cin >> n;
    long long array[n+2]; for(int i = 0; i<n; ++i)cin >> array[i];
    int ans = 0; int dif_bef = array[1] - array[0];
    for(int i = 0; i<n-1; ++i){
        int dif = array[i+1]-array[i];
        switch (dif){
            case 0:
                //cout << i << " is case 0" << endl;
                break;
            default:
                //cout << i << " is default" << endl;
                if(dif != dif_bef || abs(dif) > 1){
                    ++ans; dif_bef = array[i+1] - array[i]; //cout << i << " has increased" << endl;
                }else dif_bef = dif;
                break;
        }
    }
    cout << ans+1 << endl; return 0;
}
*/

/*Second
int main(){
    int n; cin >> n;
    long long array[n]; for(int i = 0; i<n; ++i)cin >> array[i];
    int ans = 0; int dif_bef = 0;
    for(int i = 1; i<n; ++i){
        int dif = array[i]-array[i-1];
        switch (dif){
            case 0
                break;
            default:
                if(abs(dif - dif_bef) > 1 || abs(dif) > 1){
                    ++ans; dif_bef = 0;
                }else dif_bef = dif;
                break;
        }
    }
    cout << ans+1 << endl; return 0;
}
*/

/*First
int main(){
    int n; cin >> n;
    long long array[n]; for(int i = 0; i<n; ++i)cin >> array[i];
    int ans = 0; long long dif_bef = 0;
    for(int i = 0; i<n-1; ++i){
        long long dif = array[i+1]-array[i];
        if(abs(dif - dif_bef) > 1 || abs(dif) > 1){
            ++ans; dif_bef = 0;
        }else dif_bef = dif;
    }
    cout << ans+1 << endl; return 0;
}*/


/*
int dif = array[i+1]-array[i];
        cout << sign << ',' << dif << endl;
        if(abs(dif - sign) > 1){
            ++ans; sign = (dif>0) - (dif<0);
        }
        */