#include <iostream>
using namespace std;

int main(){
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    bool water[3010] = {false}, suger[3010] = {false};
    a *= 100; b*=100;
    for(int i = 0; i<=f; i += a){
        for(int j = 0; i+j <= f; j += b)water[i+j] = true;
    }
    for(int i = 0; i<=f; i += c){
        for(int j = 0; i+j <= f; j += d)suger[i+j] = true;
    }
    //cout << water[800] << ' ' << suger[400] << endl;
    double conc[3] = {0.0, (double)a, 0.0};
    for(double i = 0.0; i <= f; ++i){
        for(double j = 0.0; j+i <= f; ++j){
            if(water[(int)i] && suger[(int)j]){
                if(conc[0] < j/(i+j) && j*100/i <= e){
                    conc[0] = j/(i+j); conc[1] = i; conc[2] = j;
                }
            }
        }
    }
    cout << conc[1] + conc[2] << ' ' << conc[2] << endl; return 0;
}

//作ることができないときに、全体量を0とするとWA出るみたい。。。。