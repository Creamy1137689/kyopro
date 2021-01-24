#include <iostream>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    int judge[14]={0,13,1,2,3,4,5,6,7,8,9,10,11,12};
    if(judge[a]>judge[b])cout<<"Alice"<<endl;
    else if(judge[a]==judge[b])cout <<"Draw"<<endl;
    else cout<<"Bob"<<endl;return 0;
}
