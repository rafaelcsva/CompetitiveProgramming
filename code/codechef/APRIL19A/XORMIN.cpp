#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x)
using namespace std;

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

typedef long long   ll;
typedef pair< int, int >    pii;
typedef pair< int, pii >    pipii;
const int N = 2e5 + 2;
const int M = 2e5 + 10;
int root = 1;
int a[N];
vector< int > adj[M];
int adj_trie1[N * 20][2];
int pt = 1;
int cur_node1 = 2;
int st[N], en[N];
const int B = 19;
int mp[N];
bool is_leaf[N];
int n;
int cnode = 1;
pipii con[N];
pii con1[N * 20];
int pt1 = 0;
int table[N][20];

void build(){
    for(int i = 0 ; i < n ; i++){
        table[i][0] = con[i].second.second;
        // while(!(1 <= mp[special_con_trie[index][i]] && mp[special_con_trie[index][i]] <= n));
    }
    
    for(int j = 1 ; (1 << j) <= n ; j++){
        for(int i = 0 ; i + (1 << j) - 1 < n ; i++){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            // while(!(1 <= table[i][j] && table[i][j] <= n));
        }
    }
}

int query(int l, int r){
    // while(!(r >= l));
    int j = int(log2(r - l + 1));
    // cout << "log = " << j << " " << table[l][j] << " " << table[r - (1 << j) + 1][j] << endl;

    // while(!(l < table.size() && (r - (1 << j) + 1) < table.size() && j < table[0].size() && j >= 0 && (r - (1 << j) + 1) >= 0));

    return min(table[l][j], table[r - (1 << j) + 1][j]);
}

void dfs(int u, int ft){
    mp[pt] = u;
    st[u] = pt;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == ft){
            continue;
        }
        // assert(!vis[v]);
        pt++;
        dfs(v, u);
    }

    en[u] = pt;
}

void insert_trie1(int number, int id){
    int cur = root;
    
    for(int i = B ; i >= 0 ; i--){
        int e = 1 << i;
        int d = 0;
        
        if(number & e){
            d = 1;
        }
        
        if(adj_trie1[cur][d] == 0){
            adj_trie1[cur][d] = cur_node1++;
        }
        
        cur = adj_trie1[cur][d];
    }
}

void insert_trie(int number, int id){
    int cur = root;

    for(int i = B ; i >= 0 ; i--){
       // while(!(1 <= cur && cur < (N * 20)));
      //  cout << "node = " << cur << endl;
        int e = 1 << i;
        int d = 0;

        if(number & e){
            d = 1;
        }

        bool ver = true;
        
        if(adj_trie1[cur][0] && adj_trie1[cur][1]){
            ver = false;    
        }
        // cout << "On insert " << number << " in step " << i << " i have " << d << endl; 

        cur = adj_trie1[cur][d];
        
        if(!ver){          
            con1[pt1++] = {cur, id};
        }

        if(i == 0){
            is_leaf[cur] = true;
        }else{
            is_leaf[cur] = false;
        }
    }
}

int mlower_bound(int i, int j, pii val, int d){
    int lo = i, hi = j;
    int r = j + 1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        pii cur;

        if(d){
            cur = {con[mid].first, con[mid].second.first};
        }else{
            cur = con1[mid];
        }

        if(cur >= val){
            r = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    while(r == -1);

    return r;
}

int mupper_bound(int i, int j, pii val){
    int lo = i, hi = j;
    int r = j + 1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        pii cur = {con[mid].first, con[mid].second.first};

        if(cur <= val){
            lo = mid + 1;
        }else{
            r = mid;
            hi = mid - 1;
        }
    }

    return r;
}

pii get_answer(int v, int k){ 
   // while(!(1 <= v && v <= n));
    // while(!(1 <= v && v <= n));
    
    int cur = root;
    int res = 0;
    
    // auto f1 = con_trie[adj_trie[root][0]].lower_bound(st[v]);
    // auto f2 = con_trie[adj_trie[root][1]].lower_bound(st[v]);
    
    // assert((f1 != con_trie[adj_trie[root][0]].end() && (*f1) <= en[v]) ||(f2 != con_trie[adj_trie[root][1]].end() && (*f2) <= en[v]) );

    for(int i = B ; i >= 0 ; i--){
       // while(!(1 <= cur && cur < (N * 20)));
       // cout << "node = " << cur << endl;
        // assert(cur >= 1 && cur < cur_node);
        int e = 1 << i;
        int target = 0;
        // int targetv = 0;

        if(k & e){
            target = 0;
        }else{
            target = 1;
        }
        
        if(adj_trie1[cur][0] == 0){
            res |= e;
            cur = adj_trie1[cur][1];
            continue;
        }else if(adj_trie1[cur][1] == 0){
            cur = adj_trie1[cur][0];
            continue;
        }
        // cout << i << " " << a[v] << " " << targetv << endl;

        // auto p = con_trie[adj_trie[cur][targetv]].find(st[v]);
        // assert(p != con_trie[adj_trie[cur][targetv]].end());

        int f = mlower_bound(0, pt1 - 1, {adj_trie1[cur][target], st[v]}, 0);
        
        if(f == pt1 || con1[f].first != adj_trie1[cur][target] || con1[f].second > en[v]){
            if(!target){
                res |= (1 << i);
            }
            
            cur = adj_trie1[cur][!target];
        }else{
            if(target){
                res |= (1 << i);
            }
            
            cur = adj_trie1[cur][target];
        }
    }
    assert(cur < cur_node1 && cur >= 1);

    // while(!is_leaf[cur]);
    // assert(cur != 0);
    // while(cur == 0 || cur >= cur_node);
    // assert((cur < N * 20));
    
    int lo = mlower_bound(0, n - 1, {res, st[v]}, 1);
    int hi = mupper_bound(0, n - 1, {res, en[v]});
    // assert(st[v] <= en[v]);
    hi--;
    // cout << lo << " " << hi << " is my result for " << res << " " << con[lo].first << " " << con[lo].second.second << " " << st[v] << " " << con[lo - 1].second.first << " " << con[lo - 1].first << endl;
    // while(tables[cur]->table.size() != special_con_trie[cur].size());
    assert(lo <= hi);

    int r = query(lo, hi);
    bool ver = true;
    int mn = 1e9;
    // assert(1 <= r && r <= n);

    // if(!(1 <= r && r <= n)){
    //     ver = false;
    //     // int mn = 1e9;
        
        // for(int i = lo ; i <= hi ; i++){
        //     mn = min(mn, mp[special_con_trie[cur][i]]);
        //     // cout << "mp = " << mp[special_con_trie[cur][i]] << endl;
        // }

        // if(mn >= 1 && mn <= n){
        //     ver = true;
        // }
    // }

    // assert(mn == r);
    // while(r != mn);
    // while(!ver);
    // asse?rt(1 <= r && r <= n);

    return {r, res ^ k};
}

int main(){
    int t;

    t = readInt();

    while(t--){
        pt1 = 0;

        int q;

        n = readInt();
        q = readInt();

        for(int i = 1 ; i <= n ; i++){
            a[i] = readInt();
        }

        for(int i = 1 ; i < n ; i++){
            int ui, vi;

            ui = readInt();
            vi = readInt();

            adj[ui].push_back(vi);
            adj[vi].push_back(ui);
        }
        
        pt = 1;
        // assert(false);
        dfs(1, 1);

        for(int i = 1 ; i <= n ; i++){
            con[i - 1] = {a[i], {st[i], i}};
        }
        
        sort(con, con + n);
        
        for(int i = 1 ; i <= n ; i++){
            insert_trie1(a[i], st[i]);
        }
        
        for(int i = 1 ; i <= n ; i++){
            // while(!(st[i] >= 1 && st[i] <= n));
            insert_trie(a[i], st[i]);
        }

        sort(con1, con1 + pt1);

        build();
        // int node = 100;

        // cout << "QUI" << endl;

        // for(int i = 1 ; i <= 10 ; i++){
        //     int ai;

        //     scanf("%d", &ai);

        //     special_con_trie[node].push_back(ai);
        // }

        // printf("Sai\n");
        // tables[node] = new SparseTable(special_con_trie[node].size());
        // tables[node]->build(node);
        // printf("construi!\n");

        // for(int i = 0 ; i < 100 ; i++){
        //     int l, r;

        //     scanf("%d %d", &l, &r);
        //     printf("consultando!");
        //     fflush(stdout);
        //     printf("min is %d\n", tables[node]->query(l, r));
        // }
        // printf("sai aqui");
        int xl = 0, vl = 0;
        
        while(q--){
            int a, b;

            a = readInt();
            b = readInt();

            xl = a ^ xl;
            vl = b ^ vl;
            
           // cout << "calling with " << xl << " " << a << endl;
            
            // while(xl <= 0){
                
            // }
            // assert(xl >= 1 && xl <= n);
            pii u = get_answer(xl, vl);

            writeInt(u.first);
            pc(' ');
            writeInt(u.second);
            pc('\n');
            
            //cout << u.first << " " << u.second << endl;
            // while(!(u.first >= 1 && u.first <= n));
          //  return 0;
            xl = u.first;
            //cout << "xl = " << xl << endl;
            vl = u.second;
        }

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }   

        for(int i = 1 ; i <= cur_node1 ; i++){
            adj_trie1[i][0] = adj_trie1[i][1] = 0;
        }
        
        cur_node1 = 2;
    
        cnode = 1;
    }

    return 0;
}