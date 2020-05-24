#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
const int mod = 1000000007;
 
ll modpow(ll a, ll n, ll mod){
  ll res = 1;
  while(n>0){
    if(n%2 == 1) res = res * a % mod;;
    a = a * a % mod;
    n /= 2;
  }
  return res;
}
 
ll comb(int n, int a){
  ll x = 1, y = 1;
  rep(i,a){
    x = x * (n-i) % mod;
    y = y * (i+1) % mod;
  }
  ll Y = modpow(y,mod-2,mod);
  cout<< Y<<endl;
  ll res = x * Y % mod;
  cout<< res<<endl;
  return res;
}
 
int main(){
  int n,a,b;
  cin >> n >> a >> b;
 
  ll ans;
  ans = modpow(2,n,mod);
  ans -= 1;
  ans -= comb(n,a);
  cout<<"---------------"<<endl;
  if(ans<0) ans += mod;
  ans -= comb(n,b);
  if(ans<0) ans += mod;
 
  cout << ans % mod << endl;
 
  return 0;
}