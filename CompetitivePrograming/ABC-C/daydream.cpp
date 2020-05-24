#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ptr[4] = { "maerd", "remaerd", "esare", "resare"};

int main(){
    string str;
    cin >> str;
    
    reverse(str.begin(), str.end());
    bool frag = false;
    for(int i = 0; i < str.size();){
        frag = false;
        for(int j = 0; j < 4; ++j){
            if(str.substr(i, ptr[j].size()) == ptr[j]) {
                i += ptr[j].size(); frag = true; 
            }
        }
        if(!frag){ cout << "NO" << endl; return 0;}
    }
    cout << "YES" << endl;
    return 0;
}