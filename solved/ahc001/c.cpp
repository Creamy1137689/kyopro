#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef vector<vector<int>> state;


bool is_spread(int id);
void fill(double dur, int width);
void init();
void adinit(int id);
void output();
void update(int id, int asp, int width);
int score();


struct d1{
    int x, y, r;
};


const int EDGE = 10000;
const double tlimit = 4700;
const double ideal_rate = 0.98;
double ntime;
double Stime;
int n;
int weightsum = 0;
vector<d1> req(200);
state ans(200, vector<int>(4));
vector<int> area(200);
vector<int> ideal(200);
vector<int> weight(EDGE*EDGE);
vector<bool> expandable(200, true);

random_device seed;
mt19937_64 gen(seed());



int main(){
    cout << "Proceccing..." << endl;
    ifstream in("./chdata/0000.txt");
    ofstream out("./chdata/0000.out");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());


    Stime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    ntime = Stime;
    init();

    fill(500, 2);

    output();
    return 0;
}



void fill(double dur, int width){
    double endtime = Stime + dur;
    while(ntime < endtime){
        ntime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        int id = gen() % n;
        /* int id = weight[gen() % weightsum]; */
        if(area[id] > ideal[id] || !expandable[id])continue;
        int asp = gen() % 4;
        update(id, asp, width);
    }
}


void update(int id, int asp, int width = 1){
    bool ok = false;
    rep(i,4){
        int dir = (asp+i) % 4;
        int ramda = 1;
        if(dir <= 1){
            if(ans[id][dir] - width < 0)continue;
        }else{
            if(ans[id][dir] + width > EDGE)continue;
            ramda = -1;
        }
        ans[id][dir] -= width*ramda;
        if(is_spread(id)){
            int height = 0;
            if(dir % 2 == 0)height = ans[id][3] - ans[id][1];
            else height = ans[id][2] - ans[id][0];
            area[id] += width * height;
            ok = true;
        }else{
            ans[id][dir] += width*ramda;
        }
    }

    if(!ok)expandable[id] = false;

}


bool is_spread(int id){
    bool res = true;
    rep(i,n){
        if(i == id)continue;
        if(! (ans[id][2] <= ans[i][0] || ans[i][2] <= ans[id][0] ||
                    ans[id][3] <= ans[i][1] || ans[i][3] <= ans[id][1]) )res = false;
    }
    return res;
}


int score(){
    double sat = 0;
    rep(i,n){
        if(ans[i][0] <= req[i].x && req[i].x < ans[i][2] &&
                ans[i][1] <= req[i].y && req[i].y < ans[i][3]){
            int s = (ans[i][2] - ans[i][0]) * (ans[i][3] - ans[i][1]);
            double t = 1 - (double)min(req[i].r, s)/(double)max(req[i].r, s);
            sat += 1 - t*t;
        }
    }
    sat /= n;
    return (int)1e9 * sat;
}


void init(){
    cin >> n;
    rep(i,n){
        cin >> req[i].x >> req[i].y >> req[i].r;
        /* int w = 10000 + req[i].r / 5000000; */
        /* for(int t = weightsum; t < weightsum + w; ++t)weight[t] = i; */
        /* weightsum += w; */
        adinit(i);
        ideal[i] = req[i].r * ideal_rate;
    }
}


void adinit(int id){
    ans[id][0] = req[id].x;
    ans[id][1] = req[id].y;
    ans[id][2] = req[id].x + 1;
    ans[id][3] = req[id].y + 1;
    area[id] = 1;
}


void output(){
    rep(i,n){
        rep(j,4){
            if(j != 0)cout << ' ';
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
