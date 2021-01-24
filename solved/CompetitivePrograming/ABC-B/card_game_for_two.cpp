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

    int result = 0;
    for(int i = n-1; i >= 0; i -= 2){
        result += a[i];
    }
    for(int i = n-2; i >= 0; i -= 2){
        result -= a[i];
    }

    cout << result << endl;
    return 0;
}