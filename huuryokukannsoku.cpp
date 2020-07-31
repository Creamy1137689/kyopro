#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int pw(double dis){
	dis *= 10;
	dis /= 60;
	double t = round(dis);
	t /= 10;
	if(0 <= t && t <= 0.2)return 0;
	if(0.3 <= t && t <= 1.5)return 1;
	if(1.6 <= t && t <= 3.3)return 2;
	if(3.4 <= t && t <= 5.4)return 3;
	if(5.5 <= t && t <= 7.9)return 4;
	if(8.0 <= t && t <= 10.7)return 5;
	if(10.8 <= t && t <= 13.8)return 6;
	if(13.9 <= t && t <= 17.1)return 7;
	if(17.2 <= t && t <= 20.7)return 8;
	if(20.8 <= t && t <= 24.4)return 9;
	if(24.5 <= t && t <= 28.4)return 10;
	if(28.5 <= t && t <= 32.6)return 11;
	if(32.7 <= t)return 12;
	return 12;
}

string dir(double deg, double dis){
	if(pw(dis) == 0)return "C";
	if(112.5 <= deg && deg < 337.5)return "NNE";
	if(337.5 <= deg && deg < 562.5)return "NE";
	if(562.5 <= deg && deg < 787.5)return "ENE";
	if(787.5 <= deg && deg < 1012.5)return "E";
	if(1012.5 <= deg && deg < 1237.5)return "ESE";
	if(1237.5 <= deg && deg < 1462.5)return "SE";
	if(1462.5 <= deg && deg < 1687.5)return "SSE";
	if(1687.5 <= deg && deg < 1912.5)return "S";
	if(1912.5 <= deg && deg < 2137.5)return "SSW";
	if(2137.5 <= deg && deg < 2362.5)return "SW";
	if(2362.5 <= deg && deg < 2587.5)return "WSW";
	if(2587.5 <= deg && deg < 2812.5)return "W";
	if(2812.5 <= deg && deg < 3037.5)return "WNW";
	if(3037.5 <= deg && deg < 3262.5)return "NW";
	if(3262.5 <= deg && deg < 3487.5)return "NNW";
	return "N";
}

int main(){
	double deg, dis;
	cin >> deg >> dis;
	cout << dir(deg, dis) << ' ' << pw(dis) << endl;
	return 0;
}
