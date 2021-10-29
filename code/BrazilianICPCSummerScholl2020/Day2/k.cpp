#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

template<typename T>
class hungarian {
public:
    int n;
    int m;
    vector< vector< T > >a;
    vector< T > u;
    vector< T > v;
    vector< int > pa;
    vector< int > pb;
    vector< int > way;
    vector< T > minv;
    vector< bool > used;
    T inf;

    hungarian(int _n, int _m) : n(_n), m(_m) {
        assert(n <= m);
        a = vector< vector< T > >(n, vector< T >(m));
        u = vector< T >(n + 1);
        v = vector< T >(m + 1);
        pa = vector< int >(n + 1, -1);
        pb = vector< int >(m + 1, -1);
        way = vector< int >(m, -1);
        minv = vector< T >(m);
        used = vector< bool >(m + 1);
        inf = numeric_limits< T >::max();
    }

    inline void add_row(int i){
        fill(minv.begin(), minv.end(), inf);
        fill(used.begin(), used.end(), false);
        pb[m] = i;
        pa[i] = m;
        int j0 = m;
        do {
            used[j0] = true;
            int i0 = pb[j0];
            T delta = inf;
            int j1 = -1;
            for(int j = 0 ; j < m ; j++){
                if(!used[j]){
                    T cur = a[i0][j] - u[i0] - v[j];
                    if(cur < minv[j]){
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if(minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for(int j = 0 ; j <= m ;j++){
                if(used[j]){
                    u[pb[j]] += delta;
                    v[j] -= delta;
                }else{
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        }while(pb[j0] != -1);

        do{
            int j1 = way[j0];
            pb[j0] = pb[j1];
            pa[pb[j0]] = j0;
            j0 = j1;
        }while(j0 != m);
    }

    inline T current_score(){
        return -v[m];
    }

    inline pair< long long, vector< int > > solve() {
        vector< int > ans(n, 0);
        for(int i = 0 ; i < n ; i++){
            add_row(i);
        }
        for(int i = 0 ; i < n ; i++){
            ans[pb[i]] = i;
        }

        return make_pair(current_score(), ans);
    }
};

const int N = 510;
const ll mx = ll(1e4) + 10;

ll prefx[N], sufx[N];
ll prefy[N], sufy[N];
ll px[N], py[N];
ll vx[N], vy[N];
vector< pair< ll, int > > x, y;

int main(){

    x.push_back({-mx, -1});
    y.push_back({-mx, -1});

    int n;

    scanf("%d", &n);    

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &px[i], &py[i]);
        x.push_back({px[i], i});
        y.push_back({py[i], i});
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &vx[i], &vy[i]);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    for(int i = 1 ; i < x.size() ; i++){
        prefx[i] = x[i].first + prefx[i - 1];
        prefy[i] = y[i].first + prefy[i - 1];
    }

    for(int i = int(x.size()) - 1 ; i >= 1 ; i--){
        sufx[i] = sufx[i + 1] + x[i].first;
        sufy[i] = sufy[i + 1] + y[i].first;
    }

    hungarian< ll > hg(n, n);
    const ll INF = ll(1e14);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int idx = lower_bound(x.begin(), x.end(), make_pair(px[i], i)) - x.begin(); 
            int idy = lower_bound(y.begin(), y.end(), make_pair(py[i], i)) - y.begin();

            ll wx = 2LL * px[i] * vx[j] + vx[j] * vx[j] * ll(n);
            ll wy = 2LL * py[i] * vy[j] + vy[j] * vy[j] * ll(n);
        
            hg.a[i][j] = INF -(wx + wy);
        }
    }

    auto u = hg.solve();

    printf("Yes\n");

    for(int i = 0 ; i < n ; i++){
        printf("%d ", u.second[i] + 1);
    }
    printf("\n");

    return 0;
}