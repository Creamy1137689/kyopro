#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin >> s;
    int alp[26] = {0};
    for(int i=0; i<s.size(); ++i){
        ++alp[s[i]-'a'];
    }
    for(int i=0; i<26; ++i){
        if(alp[i] == 0){ cout << (unsigned char)('a'+i) << endl; return 0;}
    }
    cout << "None" << endl; return 0;
}