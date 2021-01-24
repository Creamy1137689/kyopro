#include <iostream>
using namespace std;

int cmf(const void *p, const void *q){
    return *(int*)p - *(int*)q;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; ++i){
        cin >> a[i];
    }

    qsort(a, n, sizeof(int), cmf);

    int result = 1;
    for(int i = 1; i<n; ++i){
        if(a[i] > a[i-1]) ++result;
    }

    cout << result << endl;
    return 0;
}