//09, 01, 2019, 14:00:42 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 20, M = int(1e4 + 10);
int a[N][M];
int perm[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
set< int > st;
vector< int > idx;
int n, m;
const int try_cnt = 10000;
int processed[N][N], result[N][N];
int processed1[N][N], result1[N][N];

bool is_adj(int u, int v, int mid){
    if(processed[u][v] == mid || processed[v][u] == mid){
        return result[u][v];
    }   
  
    processed[u][v] = processed[v][u] = mid;

    for(int k = 0 ; k < m ; k++){
        int diff = abs(a[u][k] - a[v][k]);

        if(diff < mid){
            return result[u][v] = result[v][u] = false;
        }
    }

    return result[u][v] = result[v][u] = true;
}

bool is_adj_b(int u, int v, int mid){
    if(processed1[u][v] == mid){
        return result1[u][v];
    }

    processed1[u][v] = mid;

    for(int k = 0 ; k < m - 1 ; k++){
        int diff = abs(a[v][k] - a[u][k + 1]);

        if(diff < mid){
            return result1[u][v] = false;
        }

        // printf("%d, %d\n", diff, k);
    }

    // printf("%d passed! (%d, %d) %d\n", k, n, m, abs(a[u][0] - a[v][1]));

    return result1[u][v] = true;
}

bool can(int k){
    st.clear();
    idx.clear();

    for(int i = 0 ; i < n ; i++){
        st.insert(i);
    }

    int start = rng() % n;
    perm[0] = start;

    st.erase(start);
    int cur = 1;

    while(st.size() > 0){
        for(set< int >::iterator it = st.begin() ; it != st.end() ; it++){
            if(is_adj(perm[cur - 1], *it, k)){
                idx.push_back(*it);
            }
        }

        if(idx.size() == 0){
            return false;
        }

        int nxt = rng() % int(idx.size());

        perm[cur] = idx[nxt];
        cur++;
        st.erase(idx[nxt]);
        
        idx.clear();
    }

    if(!is_adj_b(perm[0], perm[n - 1], k)){
        return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }

    int mndiff = 1e9;

    if(n == 1){
        for(int i = 0 ; i < m - 1 ; i++){
            mndiff = min(mndiff, abs(a[0][i] - a[0][i + 1]));
        }

        cout << mndiff << endl;
        return 0;
    }

    int lo = 0, hi = 1e9 + 10;
    int r = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        bool cn = false;

        for(int i = 0 ; i < try_cnt ; i++){
            cn |= can(mid);
            
            if(cn){
                break;
            }
        }

        if(cn){
            r = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    cout << r << endl;

    return 0;
}