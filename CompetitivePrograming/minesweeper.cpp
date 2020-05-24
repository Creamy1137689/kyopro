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
    int dh[8] = {1, 1, 1, 0, -1, -1, -1, 0}, dw[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    char map[h][w], out_map[h][w] = {'0'};
    for(int i = 0; i<h; ++i)for(int j = 0; j<w; j++)cin >> map[i][j];

    for(int i = 0; i<h; ++i){
        for(int j = 0; j<w; ++j){
            int count = 0;
            if(map[i][j] == '#')out_map[i][j] = '#'; 
            
            else{
                for(int d = 0; d<8; d++){
                    int y = dh[d]+i, x = dw[d]+j;
                    if(y>=0 && y<=h-1 && x>=0 && x<=w-1)
                    if(map[y][x] == '#')++count;
                }
                out_map[i][j] = count+'0';
            }
            
        }
    }
    for(int i = 0; i<h; ++i){for(int j = 0; j<w; j++)cout << out_map[i][j]; cout << endl;}
}