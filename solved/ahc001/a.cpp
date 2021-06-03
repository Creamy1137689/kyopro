#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;

struct d1{
    int x, y, r;
};

struct state{
    int ads[200][4];
    int area[200];
    bool expandable[200];
    bool satisfied[200];

    state(){
        rep(i,200){
            area[i] = 0;
            expandable[i] = true;
            satisfied[i] = false;
        }
    }
};


void sa(state& st, double dur);
void modify(state& st, int num);
void fill(state& st, double dur, int width);
bool is_spread(state& st, int id);
void init(state& st);
void adinit(state& st, int id);
void output(state& st);
void update(state& st, int id, int asp, int width);
int score(state& st);


const int inf = 1001001000;
const int EDGE = 10000;
const double tlimit = 4700;
const double ideal_rate = 1.05;
double ntime;
double Stime;
int n;
int weightsum = 0;
vector<d1> req(200);
vector<int> ideal(200);

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
    state ans;
    init(ans);

    fill(ans, 40, 1);
    sa(ans, tlimit-100);
    fill(ans, tlimit, 1);

    output(ans);
    printf("sat:exp [%d, %d]\n", ans.satisfied[0], ans.expandable[0]);
    return 0;
}


void modify(state& st, int num){
    vector<int> chd;
    double rate = 0.3;
    int t;
    while((int)chd.size() <= num){
        t = gen() % n;
        if(st.satisfied[t]){
            chd.emplace_back(t);
            adinit(st, t);
        }
    }
    rep(i,num){
        st.expandable[chd[i]] = false;
    }
    ntime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    fill(st, ntime - Stime + rate*num*2, 1);
    rep(i,num){
        st.expandable[chd[i]] = true;
    }
    ntime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    fill(st, ntime - Stime + (1-rate)*num*2, 1);
}


void sa(state& st, double dur){
    double TIME_LIMIT = dur - duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    double start_temp = 1e7, end_temp = 0;
    int new_score, pre_score, stdcnt;
    double temp, prob;
    double endtime = Stime + dur;
    while(ntime < endtime){
        ntime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        stdcnt = 0;
        rep(i,n)if(st.satisfied[i])++stdcnt;
        state new_state = st;
        new_score = score(st);
        pre_score = score(new_state);
        temp = start_temp + (end_temp - start_temp) * (ntime-Stime) / TIME_LIMIT;
        modify(new_state, gen() % (stdcnt/2) + 1);
        prob = exp((new_score - pre_score)/temp);
        if(prob > (gen()%inf) / (double)inf){
            st = new_state;
        }
    }
}



void fill(state& st, double dur, int width){
    double endtime = Stime + dur;
    while(ntime < endtime){
        ntime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        int id = gen() % n;
        if(st.area[id] > ideal[id])st.satisfied[id] = true;
        if(st.satisfied[id] || !st.expandable[id])continue;
        int asp = gen() % 4;
        update(st, id, asp, width);
    }
}


void update(state& st, int id, int asp, int width = 1){
    bool ok = false;
    rep(i,4){
        int dir = (asp+i) % 4;
        int ramda = 1;
        if(dir <= 1){
            if(st.ads[id][dir] - width < 0)continue;
        }else{
            if(st.ads[id][dir] + width > EDGE)continue;
            ramda = -1;
        }
        st.ads[id][dir] -= width*ramda;
        if(is_spread(st, id)){
            int height = 0;
            if(dir % 2 == 0)height = st.ads[id][3] - st.ads[id][1];
            else height = st.ads[id][2] - st.ads[id][0];
            st.area[id] += width * height;
            ok = true;
        }else{
            st.ads[id][dir] += width*ramda;
        }
    }

    if(!ok)st.expandable[id] = false;

}


bool is_spread(state& st, int id){
    bool res = true;
    rep(i,n){
        if(i == id)continue;
        if(! (st.ads[id][2] <= st.ads[i][0] || st.ads[i][2] <= st.ads[id][0] ||
                    st.ads[id][3] <= st.ads[i][1] || st.ads[i][3] <= st.ads[id][1]) )res = false;
    }
    return res;
}


int score(state& st){
    double sat = 0;
    rep(i,n){
        if(st.ads[i][0] <= req[i].x && req[i].x < st.ads[i][2] &&
                st.ads[i][1] <= req[i].y && req[i].y < st.ads[i][3]){
            int s = (st.ads[i][2] - st.ads[i][0]) * (st.ads[i][3] - st.ads[i][1]);
            double t = 1 - (double)min(req[i].r, s)/(double)max(req[i].r, s);
            sat += 1 - t*t;
        }
    }
    sat /= n;
    return (int)1e9 * sat;
}


void init(state& st){
    cin >> n;
    rep(i,n){
        cin >> req[i].x >> req[i].y >> req[i].r;
        adinit(st, i);
        ideal[i] = req[i].r * ideal_rate;
    }
}


void adinit(state& st, int id){
    st.ads[id][0] = req[id].x;
    st.ads[id][1] = req[id].y;
    st.ads[id][2] = req[id].x + 1;
    st.ads[id][3] = req[id].y + 1;
    st.area[id] = 1;
    st.expandable[id] = true;
    st.satisfied[id] = false;
}


void output(state& st){
    rep(i,n){
        rep(j,4){
            if(j != 0)cout << ' ';
            cout << st.ads[i][j];
        }
        cout << "\n";
    }
}
