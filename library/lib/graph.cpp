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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;


void dijkstra(int s, vector<int>& dist, vector<vector<P>>& G){
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    dist[s] = 0;
    while(!q.empty()){
        int cost = q.top().first;
        int f = q.top().second;
        q.pop();
        if(cost > dist[f])continue;
        for(auto t:G[f]){
            if(dist[t.first] > cost + t.second){
                dist[t.first] = cost + t.second;
                q.emplace(dist[t.first], t.first);
            }
        }
    }
}



void topological_sort(int s, vector<int> &sorted, vector<bool> &visited, vector<vector<int>> &G){
    if(G[s].size() == 0){sorted.push_back(s); return ;}
    for(auto x:G[s]){
        if(!visited[x]){
            visited[x] = true;
            topological_sort(x, sorted, visited, G);
        }
    }
    sorted.push_back(s);
}
