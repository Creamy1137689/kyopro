#include <iostream>
#include <algorithm>
using namespace std;

int cmf(const void *p, const void *q){
    return (int)*(char*)p - (int)*(char*)q;
}

int main(){
    string s,t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end()); reverse(t.begin(), t.end());

    if(s < t) { cout << "Yes" << endl; return 0;}
    cout << "No" << endl; return 0;
}