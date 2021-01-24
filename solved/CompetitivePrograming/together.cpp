#include <iostream>
#include <algorithm>
using namespace std;

int ARRAY_MAX = 100000;

int main(){
    int n; cin >> n;
    int array[ARRAY_MAX] = {0};
    for(int i = 0; i<n; ++i){
        int tmp; cin >> tmp;
        ++array[tmp];
    }
    int ans = 0;
    for(int i = 0; i<ARRAY_MAX-2; ++i){
        int tmp = array[i] + array[i+1] + array[i+2];
        if(tmp > ans)ans = tmp;
    }
    cout << ans << endl;
}