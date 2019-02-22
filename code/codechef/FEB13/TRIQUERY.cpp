//15, 02, 2019, 20:12:31 Rafaelcs cpp
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

class Triangle{
    public:
    int x, y, d;
    int idx;

    bool operator<(Triangle &other){
        return (x + y) < (other.x + other.y);
    }
};

enum events_types{points_ap, beg_triangle, end_triangle};

class Event{
    public:
    int x, y;
    int type;//0 -> POINT EVENT
            //1 -> BEGIN TRIANGLE
            //2 -> END OF A TRIANGLE
    int idx;

    bool operator<(Event &other){
        int w1 = x + y;
        int w2 = other.x + other.y;

        if(w1 < w2){
            return true;
        }else if(w1 > w2){
            return false;
        }else{
            if(type == points_ap){
                return true;
            }else{
                return false;
            }
        }
    }
};

class Point{
    public:
    int x, y;
};

const int N = int(3e5 + 10);
Point points[N];
Triangle triangles[N];
int bag[N];
int BIT_X[N], BIT_Y[N];
vector< Event > events;

int LSOne(int x){
    return x & (-x);
}

void update(int BIT[], int x, int value){
    while(x < N){
        BIT[x] += value;
        x += LSOne(x);
    }
}

int query(int BIT[], int x){
    int sum = 0;

    while(x > 0){
        sum += BIT[x];
        x -= LSOne(x);
    }

    return sum;
}

int rsq(int BIT[], int l, int r){
    r = min(r, N - 1);

    return query(BIT, r) - query(BIT, l - 1);
}

void run_sweep(int n, int q){
    for(int i = 0 ; i < n ; i++){
        events.push_back({points[i].x, points[i].y, points_ap, i});
    }

    for(int i = 0 ; i < q ; i++){
        events.push_back({triangles[i].x - 1, triangles[i].y - 1, beg_triangle, i});
        events.push_back({triangles[i].x + triangles[i].d, triangles[i].y, end_triangle, i});
    }

    sort(events.begin(), events.end());

    int size_active_set = 0;

    for(int i = 0 ; i < events.size() ; i++){
        if(events[i].type == points_ap || events[i].type == beg_triangle){
            if(events[i].x == 0){
                continue;
            }

            if(events[i].type == points_ap){
                size_active_set++;
                update(BIT_X, events[i].x, 1);
                update(BIT_Y, events[i].y, 1);
                // printf("adding %d\n", events[i].idx);
            }else{
                bag[events[i].idx] = rsq(BIT_X, 1, events[i].x) + rsq(BIT_Y, 1, events[i].y) - size_active_set;
                // printf("1: %d->%d\n", events[i].idx, bag[events[i].idx]);
            }
        }else{
            events[i].x -= triangles[events[i].idx].d;
            bag[events[i].idx] = size_active_set - (rsq(BIT_X, 1, events[i].x - 1) + rsq(BIT_Y, 1, events[i].y - 1) - bag[events[i].idx]);
            // printf("2: %d->%d\n", events[i].idx, bag[events[i].idx]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;

    n = readInt();
    q = readInt();
    // scanf("%d %d", &n, &q);

    for(int i = 0 ; i < n ; i++){
        points[i].x = readInt();
        points[i].y = readInt();
        // scanf("%d %d", &points[i].x, &points[i].y);
    }

    for(int i = 0 ; i < q ; i++){
        triangles[i].x = readInt();
        triangles[i].y = readInt();
        triangles[i].d = readInt();
        // scanf("%d %d %d", &triangles[i].x, &triangles[i].y, &triangles[i].d);
    }

    run_sweep(n, q);

    for(int i = 0 ; i < q ; i++){
        writeInt(bag[i]);
        pc('\n');
        // printf("%d\n", bag[i]);
    }

    return 0;
}