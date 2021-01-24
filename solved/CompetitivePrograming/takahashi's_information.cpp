#include <iostream>
using namespace std;

int c[3][3], solve[6];

int main(){
    for(int i = 0; i<9; ++i){
        cin >> c[i/3][i%3];
    }
    solve[0] = 0;
    for(int i = 0; i<3; ++i){
        solve[3+i] = c[0][i];
    }
    solve[1] = c[1][0]-solve[3]; solve[2] = c[2][0]-solve[3];
    //for(auto x : solve)cout << x << endl;
    //cout << endl << endl;
    for(int i = 1; i<3; ++i){
        for(int j = 1; j<3; ++j){
            if(c[i][j] != (solve[i]+solve[j+3])){ cout << "No" << endl; return 0;}
        }
    }
    cout << "Yes" << endl; return 0;
}