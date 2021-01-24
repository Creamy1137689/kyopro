#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	cout<<N*(N-1)/2-N/2<<endl;
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;++j){
			if(j==((N%2)?N:N+1)-i)continue;
			cout<<i<<' '<<j<<endl;
		}
	}
}
