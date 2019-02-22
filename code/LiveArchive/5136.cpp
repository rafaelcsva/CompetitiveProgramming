//10, 02, 2019, 15:11:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, ll >  pii;

class Square{
    public:
        ll x1, y1, x2, y2;
};

class Point{
    public:
        ll x, y;
};

struct event 
{
    int ind; // Index of rectangle in rects
    bool type; // Type of event: 0 = Lower-left ; 1 = Upper-right
    event() {};
    event(int ind, int type) : ind(ind), type(type) {};
};

struct point 
{
    ll x, y;
};

const int N = int(2e6 + 10), BOUND_Y = int(2e6 + 2), BOUND_BS = int(2e6) + 10;
const int off_set = int(1e6) + 1;
pii segtree[N << 3];
int n;
event events_v[2 * N], events_h[2 * N];
Point p[N];
Square sq[N], oth[N];
int mark[N << 3];
vector< point > rects[2];
ll cur_mid;

bool compare_x(event a, event b) { 
    if(rects[a.type][a.ind].x < rects[b.type][b.ind].x){
        return true;
    }else if(rects[a.type][a.ind].x == rects[b.type][b.ind].x){
        return a.type < b.type;
    }else{
        return false;
    }
}

bool compare_y(event a, event b) { return rects[a.type][a.ind].y < rects[b.type][b.ind].y; }

int get(int node, int sz){
    if(mark[node] != cur_mid){
        mark[node] = cur_mid;
        segtree[node] = {0LL, 0LL};
    }
    
    if(segtree[node].first){
        assert(segtree[node].first > 0);
        
        return sz;
    }    
    
    return segtree[node].second;
}

void update(int node, int i, int j, int l, int r, int val){
    if(mark[node] != cur_mid){
        mark[node] = cur_mid;
        segtree[node] = {0LL, 0LL};
    }   

    if(i > r || j < l){
        return;
    }
    
    if(i >= l && j <= r){
        segtree[node].first += val;
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;
        
        update(lf, i, mid, l, r, val);
        update(rg, mid + 1, j, l, r, val);
        
        segtree[node].second = get(lf, mid - i + 1) + get(rg, j - (mid + 1) + 1);
    }
}

ll query(int node, int i, int j, int l, int r){
    if(i > r || j < l){
        return 0LL;
    }
    
    if(i >= l && j <= r){
        return get(node, j - i + 1LL);   
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;
        
        return query(lf, i, mid, l, r) + query(rg, mid + 1, j, l, r);
    }
}

bool check(event events_v[], event events_h[], int n, int e, ll side)
{
    // cout << "checando com " << side / 2LL << endl;
    // n is the number of rectangles, e = 2*n , e is the number of points (each rectangle has two points as described in declaration of rects)
    ll area = 0LL;
    // cout << e << " " << n << endl;
    sort(events_v, events_v + e, compare_x);  //Pre-sort of vertical edges
    // cout << "qassa" << endl;
    sort(events_h, events_h + e, compare_y); // Pre-sort set of horizontal edges

    event left_e = events_v[0], right_e = events_v[e - 1];
    // cout << "---> " << rects[left_e.type][left_e.ind].x << endl;
    if(rects[right_e.type][right_e.ind].x - rects[left_e.type][left_e.ind].x + 1LL != side){
        // cout << rects[right_e.type][right_e.ind].x - rects[left_e.type][left_e.ind].x + 1LL << " " << side << " falhou de inicio" << endl;
        return true;
    }

    // cout << "qassa" << endl;
   //  cout << "adding " << rects[events_v[0].ind][0].y << " --- " << rects[events_v[0].ind][1].y << endl;
    // cout << "union_area" << endl;

    // ll last_delta_y = 0LL;
    ll last = 0;
    bool ok = false;

    for (int i = 0; i < e ; ++i){ // Vertical sweep line
        event c = events_v[i];
        // Delta_x: Distance between current sweep line and previous sweep line
        // ll delta_x = rects[c.type][c.ind].x - rects[events_v[i - 1].type][events_v[i - 1].ind].x;
        
        // cout << rects[c.type][c.ind].x << endl;

        if(i != 0 && last + 1LL < rects[c.type][c.ind].x){
            // cout << "verificado" << endl;

            ll tmp = query(1, 1, BOUND_Y, 1, BOUND_Y);

            if(tmp != side){
                // cout << tmp << " " << side << endl;
                cout << "aqui deu! " << tmp << " " << side << " " << last + 1LL << " " << rects[c.type][c.ind].x << endl;
                ok = true;
            }
        }

        last = rects[c.type][c.ind].x;
        if(c.type == 0){
            // cout << "adding " << rects[0][c.ind].y - off_set << " --- " << rects[1][c.ind].y - off_set << " " << rects[0][c.ind].x << endl;
            update(1, 1, BOUND_Y, rects[0][c.ind].y, rects[1][c.ind].y, 1);

            event d = events_v[i + 1];

            if(rects[0][d.ind].x == rects[0][c.ind].x && d.type == 0){
                continue;
            }
        }
        
        ll delta_y = query(1, 1, BOUND_Y, 1, BOUND_Y);//length of the vertical sweep line cut by rectangles
        // cout << "we have " << delta_y << " my side is " << side << " " << c.type  << endl;
        // last_delta_y = delta_y; =
        if(delta_y != side){
            ok = true;
        }
        
        if(c.type == 1){
            // cout << "erase " << rects[0][c.ind].y - off_set << " --- " << rects[1][c.ind].y - off_set << " " << rects[1][c.ind].x << endl;
            update(1, 1, BOUND_Y, rects[0][c.ind].y, rects[1][c.ind].y, -1);

            int j = i + 1;

            while(j < e && rects[events_v[j].type][events_v[j].ind].x == rects[c.type][c.ind].x){
                if(events_v[j].type == 0){
                    // assert(false);
                    // cout << "adding " << rects[0][events_v[j].ind].y - off_set << " --- " << rects[1][events_v[j].ind].y - off_set << endl;
                    update(1, 1, BOUND_Y, rects[0][events_v[j].ind].y, rects[1][events_v[j].ind].y, 1);
                }else{
                    // assert(false);
                    // cout << "erase1 " << rects[0][events_v[j].ind].y - off_set << " --- " << rects[1][events_v[j].ind].y - off_set << " " <<  endl;
                    update(1, 1, BOUND_Y, rects[0][events_v[j].ind].y, rects[1][events_v[j].ind].y, -1);
                }

                i = j;
                j++;
            }
        }
        //in_set[c.ind] = (c.type==0);//If it is a left edge, the rectangle is in the active set else not
    }

    return ok;
}

Square join(Square &a, Square &b){
    return {max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}

bool exists(Square &t){
    return t.x1 <= t.x2 && t.y1 <= t.y2;
}

bool can(ll mid){
    // memset(segtree, 0LL, sizeof segtree);
    rects[0].clear();
    rects[1].clear();
    
    for(int i = 0 ; i < n ; i++){
        sq[i] = {p[i].x - mid, p[i].y - mid, p[i].x + mid, p[i].y + mid};
        // cout << "x = " << p[i].x + mid << endl;
    }

    sq[n] = {-mid, -mid, mid, mid};

    for(int i = 0 ; i < n ; i++){
        Square t = join(sq[i], sq[n]);

        if(exists(t)){
            // cout << "pushing " << t.x2 << endl;
            rects[0].push_back({t.x1, t.y1});
            rects[1].push_back({t.x2, t.y2});
        }
    }
    // cout << "auiq" << endl;
    int nn = int(rects[0].size());
    cout << "n = " << n << " " << nn << endl;

    for(int i = 0 ; i < nn ; i++){
        rects[0][i].y += off_set;
        rects[1][i].y += off_set;

        events_v[i * 2].ind = i;
        events_v[i * 2].type = 0;
        events_v[i * 2 + 1].ind = i;
        events_v[i * 2 + 1].type = 1;
        
        events_h[i * 2].ind = i;
        events_h[i * 2].type = 0;
        events_h[i * 2 + 1].ind = i;
        events_h[i * 2 + 1].type = 1;
    }

    // cout << "aqui" << endl;
    // cout << "n = " << n << " " << mid << endl;
    if(nn == 0){
        return true;
    }
    // cout << union_area(events_v, events_h, n, 2 * n) << " " << 4LL * mid * mid << " for " << mid << endl;

    return check(events_v, events_h, nn, 2 * nn, 2LL * mid + 1LL); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(cin >> n){
        if(n == -1){
            break;
        }

        for(int i = 0 ; i < n ; i++){
            cin >> p[i].x >> p[i].y;
        }

        ll lo = 0LL, hi = BOUND_BS;
        ll r = 0LL;

        while(lo <= hi){
            ll mid = (lo + hi) >> 1;
            cur_mid = mid;
            // cout << "tentando com " << mid << endl;

            if(can(mid)){
                // cout << "--- deu certo" << endl;
                r = mid;
                lo = mid + 1;
            }else{
                // cout << "--- nao deu certo" << endl;
                hi = mid - 1;
            }
        }

        cout << "Case " << test++ << ": ";
        cout << can(8) << endl;

        if(r >= BOUND_BS){
            cout << "never" << endl;
        }else{
            cout << r + 1 << endl;
        }

        memset(mark, -1LL, sizeof mark);
    }   

    return 0;
}