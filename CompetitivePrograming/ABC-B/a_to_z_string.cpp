#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int f = 0, e = s.size()-1;
    for(; f<s.size()-1; ++f){
        if(s[f] == 'A'){break;}
    }
    for(; e>=0; --e){
        if(s[e] == 'Z'){break;}
    }

    cout << e-f+1 << endl; return 0;
}