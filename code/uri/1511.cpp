#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

class SegTree {
    int nodes[N << 2];

    int query(int node, int i, int j, int l, int r){
        if(j < l || i > r){
            return 0;
        }

        if(l <= i && j <= r){
            return nodes[node];
        }else{
            int mid = (i + j) >> 1;
            int lf = node << 1;
            int rg = lf + 1;

            return __gcd(query(lf, i, mid, l, r), query(rg, mid + 1, j, l, r));
        }
    }

    void update(int node, int i, int j, int pos, int val){
        if(j < pos || i > pos){
            return;
        }

        if(i == pos && j == pos){
            nodes[node] = val;
        }else{
            int mid = (i + j) >> 1;
            int lf = node << 1;
            int rg = lf + 1;

            update(lf, i, mid, pos, val);
            update(rg, mid + 1, j, pos, val);

            nodes[node] = __gcd(nodes[lf], nodes[rg]);
        }
    }

    public:
        //retorna o valor associado ao gcd na regiao [l, r]
        int get(int l, int r){
            return query(1, 1, N, l, r);
        }

        //coloca val na posicao pos
        void set(int pos, int val){
            update(1, 1, N, pos, val);
        }
};

const int M = int(1e5) + 10;
const int offset = 501;
const int maxy = 1001, miny = 1;
const int maxx = 1001, minx = 1;
SegTree rows[N];
string qu[M];
int x[M], y[M], d[M];

int main(){
    /* as proximas duas linhas eh apenas para acelerar a leitura..*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    while(cin >> q){
        for(int i = 0 ; i < q ; i++){
            cin >> qu[i] >> x[i] >> y[i] >> d[i];

            //ajustando indices para evitar valores negativos..
            x[i] += offset;
            y[i] += offset;

            if(qu[i] == "QUERY"){
                int g = 0;

                int tmpy = y[i];
                int tmpd = d[i];
                while(tmpy <= maxy && tmpd >= 0){
                    g = __gcd(g, rows[tmpy].get(max(minx, x[i] - tmpd), min(maxx, x[i] + tmpd)));
                    tmpd--;
                    tmpy++;
                }
                
                tmpy = y[i] - 1;
                tmpd = d[i] - 1;

                while(tmpy >= miny && tmpd >= 0){
                    g = __gcd(g, rows[tmpy].get(max(minx, x[i] - tmpd), min(maxx, x[i] + tmpd)));
                    tmpd--;
                    tmpy--;
                }

                cout << g << "\n";
            }else{
                rows[y[i]].set(x[i], d[i]);
            }
        }

        //limpar segtrees para prox test
        for(int i = 0 ; i < q ; i++){
            if(qu[i] == "SET"){
                rows[y[i]].set(x[i], 0);
            }
        }
    }

    return 0;
}
