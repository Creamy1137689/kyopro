#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    string s; cin>>s;
    rep(i,s.size()){
        if(i%2==0){
            if(s[i]=='R'||s[i]=='U'||s[i]=='D');
            else {cout<<"No"<<endl;return 0;}
        }else{
            if(s[i]=='L'||s[i]=='U'||s[i]=='D');
            else {cout<<"No"<<endl;return 0;}
        }
    }
    cout<<"Yes"<<endl;return 0;
}
