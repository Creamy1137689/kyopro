#include <iostream>
using namespace std;

int main(){
    int k,s;
    cin >> k >> s;

    int result = 0;
    for(int x = 0; x <= k; ++x){
        for(int y = 0; y <= k && x+y <= s; ++y){
            if(s-x-y <= k){++result;}
        }
    }
    
    cout << result << endl; return 0;
}