#include <iostream>
using namespace std;

bool check1(int t, int nt, int x, int nx, int y, int ny){
    return (t-nt) != (abs(x-nx)+abs(y-ny));
}

bool check2(int t, int nt, int x, int nx, int y, int ny){
    if((t-nt) >= (abs(x-nx)+abs(y-ny)) && ((t-nt) - (abs(x-nx)+abs(y-ny))) % 2 == 0) return false;
    return true;
}

int main(){
    int n;
    cin >> n;

    int t[n], x[n], y[n] ;
    for(int i=0; i<n; ++i){
        cin >> t[i] >> x[i] >> y[i];
    }
    int nx = 0, ny = 0, nt = 0;
    for(int i=0; i<n; ++i){
        if(check2(t[i], nt, x[i], nx, y[i], ny)){
            cout << "No" << endl;
            return 0;
        }
        nx = x[i]; ny = y[i]; nt = t[i];
    }
    cout << "Yes" << endl;
    return 0;
}