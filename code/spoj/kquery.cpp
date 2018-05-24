//22, 05, 2018, 19:25:59 Rafaelcs cpp
#include <bits/stdc++.h>

#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x)

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(3e4 + 100);
int v[N];
int bit[N];

inline int readInt()
{
    bool minus = false;
    register int result = 0;
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
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}
 
inline void writeInt ( int n )
{
    register int N = n, rev, count = 0 ;
    rev = N ;
    if (N == 0) 
    { 
        pc('0');  return ;
    }
    while ((rev % 10) == 0) 
    { 
        count++; rev /= 10;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) 
    { 
        rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;
    }  //store reverse of N in rev
    while (rev != 0) 
    { 
        pc(rev % 10 + '0'); rev /= 10 ;
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

int LSOne(int a){
    return a & (-a);
}

int rsq(int a){
    int r = 0;

    while(a){
        r += bit[a];
        a -= LSOne(a);
    }

    return r;
}

void update(int a){
    while(a < N){
        bit[a] += 1;
        a += LSOne(a);
    }
}

int getSum(int a, int b){
    return rsq(b) - rsq(a - 1);
}

typedef struct{
    int type, value, l, r, qpos, apos;
}Query;

vector<Query>q;
vector<pii>r;

bool compar(Query a, Query b){
    if(a.value != b.value){
        return a.value > b.value;
    }

    return a.type > b.type;
}

bool compar1(pii a, pii b){
    return a.second < b.second;
}
int main(){
    int n;
    
    n = readInt();

    for(int i = 1 ; i <= n ; i++){
        v[i] = readInt();
        q.push_back({1, v[i], -1, -1, -1, i});
    }
    
    int m;
    
    m = readInt();

    for(int i = 0 ; i < m ; i++){
        int l, r, v;

        l = readInt(), r = readInt(), v = readInt();

        q.push_back({2, v, l, r, i, -1});
    }

    sort(q.begin(), q.end(), compar);

    for(int i = 0 ; i < q.size() ; i++){
        Query u = q[i];
        
        if(u.type == 1){
            update(u.apos);
        }else{
            r.push_back({getSum(u.l, u.r), u.qpos});
        }
    }
    
    sort(r.begin(), r.end(), compar1);
    
    for(int i = 0 ; i < r.size() ; i++){
        writeInt(r[i].first);
        printf("\n");
    }
    
    return 0;
}