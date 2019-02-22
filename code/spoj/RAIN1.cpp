//12, 02, 2019, 19:45:43 Rafaelcs cpp
#include <bits/stdc++.h>

#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x)

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

inline int readInt()
{
    bool minus = false;
    register ll result = 0;
    register char ch = getchar_unlocked();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break ;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; 
    else result = ch-'0';
    while (true)
    {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10LL + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}
 
inline void writeInt ( int n )
{
    register ll N = n, rev, count = 0 ;
    rev = N ;
    if (N == 0) 
    { 
        pc('0');  return ;
    }
    while ((rev % 10LL) == 0LL) 
    { 
        count++; rev /= 10LL;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0LL) 
    { 
        rev = (rev<<3LL) + (rev<<1LL) + N % 10LL; N /= 10LL;
    }  //store reverse of N in rev
    while (rev != 0LL) 
    { 
        pc(rev % 10LL + '0'); rev /= 10LL ;
    }
    while (count--) pc('0') ;
}
 
inline void write_string(char *str)
{
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked() ;
    while (c != '\n') 
    {
        str[i] = c;
        c = getchar_unlocked() ;
        i = i + 1;
    }
    str[i] = '\0';
}

class Segment{
    public:
    ll x1, y1, x2, y2;
};

const int N = int(4e4 + 100), D = 30;
Segment seg[N];
int cur = 0;

class Event{
    public:
    int ind;
    int type;

    bool operator <(Event &other){
        int a, b;

        if(type){
            a = seg[ind].x2;
        }else{
            a = seg[ind].x1;
        }

        if(other.type){
            b = seg[other.ind].x2;
        }else{
            b = seg[other.ind].x1;
        }
        
        if(a < b){
            return true;
        }else if(a > b){
            return false;
        }else if(type != other.type){
            return type == 0;
        }

        int x = min(seg[ind].x2, seg[other.ind].x2);
        double alp1 = double(seg[ind].y2 - seg[ind].y1) / double(seg[ind].x2 - seg[ind].x1);
        double alp2 = double(seg[other.ind].y2 - seg[other.ind].y1) / double(seg[other.ind].x2 - seg[other.ind].x1);

        return (alp1 * (x - seg[ind].x1) + seg[ind].y1) < (alp2 * (x - seg[other.ind].x1) + seg[other.ind].y1);
    }
};

class Segment_Node{
    public:
    int ind;

    bool operator <(const Segment_Node other) const{
        ll x = min(seg[ind].x2, seg[other.ind].x2);
        double alp1 = double(seg[ind].y2 - seg[ind].y1) / double(seg[ind].x2 - seg[ind].x1);
        double alp2 = double(seg[other.ind].y2 - seg[other.ind].y1) / double(seg[other.ind].x2 - seg[other.ind].x1);

        return (alp1 * (x - seg[ind].x1) + seg[ind].y1) < (alp2 * (x - seg[other.ind].x1) + seg[other.ind].y1);
    }

    // bool operator ==(Segment_Node &other) const{
    //     return ind == other.ind;
    // }
};

set< Segment_Node > set_sweep;
Event events[2 * N];
vector< int > adj[N];
set< Segment_Node >::iterator it;
ll ret[N];
ll have[N];
int color[N];
enum colors{white, black};
vector< int > topological_sort;

void run_adj(Event events[], int n){
    // assert(set_sweep.size() == 0);
    // cout << "n ===== " << n << endl;
    sort(events, events + n);

    set_sweep.insert({events[0].ind});

    for(int i = 1 ; i < n ; i++){
        // assert(set_sweep.size() <= D);

        Event d = events[i];
        Segment_Node c = {d.ind};

        if(d.type == 0){
            // cout << "adding segment idx = " << c.ind << endl;
            set_sweep.insert(c);
        }else{
            // assert(set_sweep.size() != 0);
            it = set_sweep.lower_bound(c);
            
            if(adj[c.ind].size() == 0 && it != set_sweep.begin()){
                it = prev(it);
                ll x;

                if(seg[c.ind].y1 < seg[c.ind].y2){
                    x = seg[c.ind].x1;
                }else{
                    x = seg[c.ind].x2;
                }

                while(true){
                    if(seg[it->ind].x1 <= x && x <= seg[it->ind].x2){
                        // cout << "adding edge " << c.ind << " -> " << it->ind << endl;
                        adj[c.ind].push_back(it->ind);
                        break;
                    }

                    if(it == set_sweep.begin()){
                        break;
                    }
                }
            }

            it = set_sweep.lower_bound(c);
            // it = set_sweep.find(c);
            it = next(it);

            ll l = seg[c.ind].x1, r = seg[c.ind].x2;

            while(true){
                if(it == set_sweep.end() || l > r){
                    break;
                }

                ll x;

                if(seg[it->ind].y1 < seg[it->ind].y2){
                    x = seg[it->ind].x1;
                }else{
                    x = seg[it->ind].x2;
                }

                if(l <= x && x <= r){
                    // cout << "adding edge " << it->ind << " -> " << c.ind << endl;
                    adj[it->ind].push_back(c.ind);
                    break;
                }

                r = min(r, seg[it->ind].x1 - 1LL);

                it = next(it);
            }

            // cout << "removing segment idx = " << c.ind << endl;
            // cout << set_sweep.size() << " -> ";
            set_sweep.erase(c);
            // cout << set_sweep.size() << endl;
        }
    }
}

void sweep_main(int n){
    // assert(set_sweep.size() == 0);

    set_sweep.insert({events[0].ind});

    ll begin_x = seg[events[0].ind].x1;

    for(int i = 1 ; i < n ; i++){
        // assert(set_sweep.size() <= D);

        ll end_x;
        ll tmp = begin_x;

        if(events[i].type){
            end_x = seg[events[i].ind].x2;
            // cout << "processing remove of " << events[i].ind << endl;
        }

        if(events[i].type){
            // assert(set_sweep.size() != 0);
            if(set_sweep.size() == 1 || begin_x > end_x){
                // cout << "removing segment idx = " << events[i].ind << endl;
                set_sweep.erase({events[i].ind});
                continue;
            }

            it = prev(set_sweep.end());
            begin_x = seg[it->ind].x1;
            begin_x = max(begin_x, tmp);
            // cout << "begin with " << it->ind << endl;
            // end_x = max(end_x, events[it->ind].x2);
            it = prev(it);

            while(true){
                // cout << "computing in " << it->ind << endl;

                if(begin_x > seg[it->ind].x1){
                    ret[it->ind] += (end_x - begin_x);
                }else{
                    ret[it->ind] += (end_x - seg[it->ind].x1);
                }

                begin_x = min(begin_x, seg[it->ind].x1);
                begin_x = max(begin_x, tmp);
                // end_x = max(end_x, events[it->ind].x2);

                if(it == set_sweep.begin()){
                    break;
                }

                it = prev(it);
            }

            begin_x = end_x;
            // cout << "removing segment idx = " << events[i].ind << endl;
            set_sweep.erase({events[i].ind});
        }else{
            // cout << "adding segment idx = " << events[i].ind << endl;
            set_sweep.insert({events[i].ind});
        }
    }
}

void dfs(int u){
    color[u] = black;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(color[v] == white){
            dfs(v);
        }
    }

    topological_sort.push_back(u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    t = readInt();

    while(t--){
        int n;

        n = readInt();

        for(int i = 0 ; i < n ; i++){
            seg[i].x1 = readInt();
            seg[i].y1 = readInt();
            seg[i].x2 = readInt();
            seg[i].y2 = readInt();
            // printf("lii tudin!\n");
            // writeInt(seg[i].x1);
            // scanf("%lld %lld %lld %lld", &seg[i].x1, &seg[i].y1, &seg[i].x2, &seg[i].y2);

            events[i * 2].ind = i;
            events[i * 2].type = 0;

            events[i * 2 + 1].ind = i;
            events[i * 2 + 1].type = 1;
        }

        // for(int i = 0 ; i < 2 * n  ; i++){
        //     cout << events[i].ind << " " << events[i].type << endl;
        // }
        // cout << "running adj" << endl;
        run_adj(events, 2 * n);
        // cout << "ended" << endl;
        // cout << "running sweep" << endl;
        sweep_main(2 * n);
        // cout << "ended" << endl;

        for(int i = 0 ; i < n ; i++){
            ll delta_x = seg[i].x2 - seg[i].x1;
            // ll delta_y = abs(seg[i].y2 - seg[i].y1);
            // ll g = __gcd(delta_x, delta_y);

            // cout << "i: " << i << " " << delta_x << " " << ret[i] << endl;
            have[i] = delta_x - ret[i];
        }

        for(int i = 0 ; i < n ; i++){
            if(color[i] == white){
                dfs(i);
            }
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            int u = topological_sort[i];

            assert(adj[i].size() <= 1);
            
            for(int j = 0 ; j < adj[u].size() ; j++){
                int v = adj[u][j];

                have[v] += have[u];
            }

            adj[u].clear();
        }

        for(int i = 0 ; i < n ; i++){
            // char c = (i == n - 1) ? '\n' : ' ';
            // printf("%lld\n", have[i]);
            writeInt(have[i]);
            pc('\n');
            color[i] = have[i] = ret[i] = 0LL;
        }

        topological_sort.clear();
        // memset(have, 0LL, sizeof have);
        // memset(ret, 0LL, sizeof ret);
        // memset(seg, 0, sizeof seg);
        // memset(events, 0, sizeof events);
        // memset(color, 0, sizeof color);
    }

    // assert(op <= max_op);

    return 0;
}