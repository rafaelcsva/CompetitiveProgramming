//26, 02, 2019, 19:04:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, ll >  pll;

const int N = int(1e5 + 10);
pll rectangle[N][2];

struct event{
    public:
    int type;
    int idx;

    event(){

    }

    event(int tpe, int id){
        this->type = tpe;
        this->idx = id;
    }
};

struct fraction{
    public:
    ll num;
    ll dem;

    fraction(ll nm, ll dm){
        this->num = nm;
        this->dem = dm;
    }

    fraction(){
        
    }

    void simplify(){
        ll g = __gcd(this->num, this->dem);

        this->num /= g;
        this->dem /= g;
    }

    bool operator <(fraction &other){
        return this->num * other.dem < other.num * this->dem;
    }
};

fraction dis(int idx, ll mx){
    fraction da;

    if(rectangle[idx][1].first == rectangle[idx][0].first){
        da = fraction( rectangle[idx][1].second, 1LL );
    }else{
        fraction m_angle = fraction((rectangle[idx][1].second - rectangle[idx][0].second) ,
        (rectangle[idx][1].first - rectangle[idx][0].first) );

        da = fraction(m_angle.num * (mx - rectangle[idx][0].first) + m_angle.dem * rectangle[idx][0].second, m_angle.dem);
    }

    assert(da.num >= 0 && da.dem >= 0);

    da.simplify();

    return da;
}

struct MNode{
    public:
    int idx;

    MNode(){

    }

    MNode(int id){
        this->idx = id;
    }

    bool operator <(MNode other) const{
        fraction da, db;

        ll mx = min(rectangle[other.idx][1].first, rectangle[this->idx][1].first);

        da = dis(this->idx, mx);
        db = dis(other.idx, mx);

        return da < db;
    }
};

vector< event > events;
pii balls[N];
int adj[N];
int adj_balls[N];
set< MNode > st;
int resp[N];

bool compar(event &a, event &b){
    // cout << a.idx << " " << a.type << " " << b.idx << " " << b.type << endl;
    int xa, xb;
    int ya, yb;

    if(a.type <= 1){
        xa = rectangle[a.idx][a.type].first;
        ya = rectangle[a.idx][a.type].second;
    }else{
        xa = balls[a.idx].first;
        ya = balls[a.idx].second;
    }

    if(b.type <= 1){
        xb = rectangle[b.idx][b.type].first;
        yb = rectangle[b.idx][b.type].second;
    }else{
        xb = balls[b.idx].first;
        yb = balls[b.idx].second;
    }

    if(xa < xb){
        return true;
    }else if(xa > xb){
        return false;
    }else{
        if((a.type == 0 || a.type == 2) && b.type == 1){
            return true;
        }
        
        return ya < yb;
    }
}

int m_point(int u){
    int mx;

    if(rectangle[u][0].second > rectangle[u][1].second){
        mx = rectangle[u][1].first;
    }else{
        mx = rectangle[u][0].first;
    }

    return mx;
}

bool intersect(int u, int v){
    int mx = m_point(u);

    return rectangle[v][0].first <= mx && mx <= rectangle[v][1].first;
}

void line_sweep(){
    // cout << "tenho " << events.size() << " eventos" << endl;
    sort(events.begin(), events.end(), compar);
    // cout << "ja ordenei!" << endl;

    for(int i = 0 ; i < events.size() ; i++){
        event u = events[i];

        if(u.type == 2){
            rectangle[N - 1][0] = rectangle[N - 1][1] = balls[u.idx];

            auto d = st.lower_bound(MNode(N - 1));

            if(d == st.end()){
                d = prev(d);
            }
            // cout << u.idx + 1 << " " << d->idx + 1<< endl;
            if(d == st.begin() && MNode(N - 1) < MNode(d->idx)){
                // cout << "sou di menor" << endl;
                continue;
            } 

            if(MNode(N - 1) < MNode(d->idx)){
                // if(u.idx == 0){
                //     cout << "dei prev aqui" << endl;
                // }
                d = prev(d);
            }   

            adj_balls[u.idx] = d->idx;
            // if(u.idx == 0){
            //     cout << "d = " << d->idx << " " << rectangle[N - 1][0].first << endl;
            // }
        }else{
            if(u.type == 1){
                auto d = st.lower_bound(MNode(u.idx));

                auto nxt = next(d);
                // auto pv = prev(d);

                if(nxt != st.end()){
                    if(intersect(nxt->idx, d->idx) && rectangle[nxt->idx][1].first == m_point(nxt->idx)){
                        adj[nxt->idx] = d->idx;
                    }
                }

                // if(d != st.begin()){
                //     auto pv = prev(d);

                //     if(intersect(d->idx, pv->idx)){
                //         adj[d->idx] = pv->idx;
                //     }
                // }

                st.erase(d);
            }else{
                st.insert(MNode(u.idx));
                auto d = st.find(MNode(u.idx));
                
                if(d != st.begin()){
                    auto pv = prev(d);
                    if(intersect(d->idx, pv->idx) && rectangle[d->idx][0].first == m_point(d->idx)){
                        adj[d->idx] = pv->idx;
                    }
                }
            }
        }
    }

    st.clear();
    events.clear();
}

int get_resp(int u){
    if(resp[u] != -1){
        return resp[u];
    }

    if(adj[u] == -1){
        return m_point(u);
    }
    // cout << u << " -> " << adj[u] << endl;

    resp[u] = get_resp(adj[u]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        memset(adj_balls, -1, sizeof adj_balls);
        memset(adj, -1, sizeof adj);
        memset(resp, -1, sizeof resp);

        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> rectangle[i][0].first >> rectangle[i][0].second >> rectangle[i][1].first >> rectangle[i][1].second;

            if(rectangle[i][1].first < rectangle[i][0].first){
                swap(rectangle[i][1], rectangle[i][0]);
            }
        }

        int m;

        cin >> m;

        for(int i = 0 ; i < m ; i++){
            cin >> balls[i].first >> balls[i].second;
        }       
        // cout << "aqui" << endl;

        for(int i = 0 ; i < n ; i++){
            events.push_back(event(0, i));
            events.push_back(event(1, i));
        }

        for(int i = 0 ; i < m ; i++){
            events.push_back(event(2, i));
        }
        // cout << "rodando o line sweep" << endl;

        line_sweep();
        // cout << "rodei cara!" << endl;

        for(int i = 0 ; i < m ; i++){
            if(adj_balls[i] == -1){
                cout << balls[i].first << endl;
            }else{
                // cout << adj_balls[i] << endl;
                cout << get_resp(adj_balls[i]) << endl;
            }
        }
    }
    
    return 0;
}