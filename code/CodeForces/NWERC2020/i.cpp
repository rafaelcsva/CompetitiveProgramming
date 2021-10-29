#include <bits/stdc++.h>

using namespace std;

const int N = 410;
int d[N], t[3][N];
int n;
int ans[10];

class state {
    public:
        int pos, dis, cnt, idx;
};

bool same_pos(state a, state b){
    if(a.cnt == n || b.cnt == n) return false;

    if(a.dis >= t[a.idx][a.pos] || b.dis >= t[b.idx][b.pos]){
        return false;
    }

    return a.pos == b.pos;
}

bool is_possible(state a, state b, state c){
    while(((a.cnt != n) + (b.cnt != n) + (c.cnt != n)) > 1){
        if(same_pos(a, b) || same_pos(a, c) || same_pos(b, c)){
            // printf("ruim em (%d, %d, %d %d) (%d, %d, %d, %d .. %d)\n", a.pos, a.dis, a.cnt, a.idx, b.pos, b.dis, b.cnt, b.idx, t[b.idx][b.pos]);
            return false;
        }

        int minmov = int(1e9);

        if(a.cnt != n){
            minmov = t[a.idx][a.pos] + ((a.cnt != n - 1) ? d[a.pos] : 0) - a.dis;
        }

        if(b.cnt != n){
            minmov = min(t[b.idx][b.pos] + ((b.cnt != n - 1) ? d[b.pos] : 0) - b.dis, minmov);
        }

        if(c.cnt != n){
            minmov = min(t[c.idx][c.pos] + ((c.cnt != n - 1) ? d[c.pos] : 0) - c.dis, minmov);
        }

        if(a.cnt != n){
            a.dis += minmov;
            if(a.dis == t[a.idx][a.pos] + ((a.cnt != n - 1) ? d[a.pos] : 0)){
                a.pos = (a.pos + 1) % n;
                a.cnt++;
                a.dis = 0;
            }
        }

        if(b.cnt != n){
            b.dis += minmov;
            if(b.dis == t[b.idx][b.pos] + ((b.cnt != n - 1) ? d[b.pos] : 0)){
                b.pos = (b.pos + 1) % n;
                b.cnt++;
                b.dis = 0;
            }
        }

        if(c.cnt != n){
            c.dis += minmov;
            if(c.dis == t[c.idx][c.pos] + ((c.cnt != n - 1) ? d[c.pos] : 0)){
                c.pos = (c.pos + 1) % n;
                c.cnt++;
                c.dis = 0;
            }
        }
    }

    return true;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &d[i]);
    }

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &t[i][j]);
        }
    }

    vector< int > v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    bool frag = false;

    // printf("r: %d\n", is_possible({5, 0, 0, 2}, {0, 0, 0, 0}, {0, 0, n, 0}));

    do {
        // printf("testando perm: %d %d %d\n", v[0], v[1], v[2]);
        for(int i = 0 ; i < n ; i++){
            int pj = -1;

            for(int j = 0 ; j < n ; j++){
                int tpj = (i + j) % n;
                // printf("testando pos (%d, %d)\n", i, tpj);
    
                if(is_possible({i, 0, 0, v[0]}, {tpj, 0, 0, v[1]}, {0, 0, n, 0})){
                    // printf("%d %d (%d, %d)\n", i, tpj, v[0], v[1]);
                    pj = tpj;
                    break;
                }
            }

            if(pj == -1) continue;

            int pk = -1;

            for(int k = 0 ; k < n ; k++){
                int tpk = (pj + k) % n;

                if(is_possible({pj, 0, 0, v[1]}, {tpk, 0, 0, v[2]}, {0, 0, n, 0})){
                    // printf("%d %d (%d, %d)\n", pj, tpk, v[0], v[1]);
                    pk = tpk;
                    break;
                }
            }

            if(pk == -1) continue;

            // printf("%d %d %d, %d %d %d\n", v[0], v[1], v[2], i, pj, pk);

            if(is_possible({i, 0, 0, v[0]}, {pj, 0, 0, v[1]}, {pk, 0, 0, v[2]})){
                frag = true;
                ans[v[0]] = i + 1;
                ans[v[1]] = pj + 1;
                ans[v[2]] = pk + 1;
                break;
                // printf("%d %d %d\n", ans[0], ans[1], ans[2]);
            }
        }
    }while(next_permutation(v.begin(), v.end()));

    if(!frag){
        printf("impossible\n");
    }else{
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }

    return 0;
}
