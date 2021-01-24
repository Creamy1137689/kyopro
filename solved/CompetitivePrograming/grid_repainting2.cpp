#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int h,w; cin >> h >> w;
    int dh[4] = {1,0,-1,0}, dw[4] = {0,1,0,-1};
    char map[h][w];
    for(int i = 0; i<h; ++i)for(int j = 0; j<w; j++)cin >> map[i][j];

    for(int i = 0; i<h; ++i){
        for(int j = 0; j<w; ++j){
            if(map[i][j] == '#'){
                bool is_incor = true;
                for(int d = 0; d<4; ++d){
                    int x = j+dw[d], y = i+dh[d];
                    if(y>=0 && y<=h-1 && x>=0 && x<=w-1){
                        if(map[y][x] == '#')is_incor = false;
                    }
                }
                if(is_incor) {cout << "No" << endl; return 0;}
            }
        }
    }
    cout << "Yes" << endl; return 0;
}