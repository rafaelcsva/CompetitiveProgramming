//01, 10, 2018, 13:20:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int C = 4, L = 4, D = 7;

struct Dice{
    int up, right, down, left, center;
};

Dice rotate(char dir, Dice c){
    int mark[D];
    memset(mark, 0, sizeof mark);

    mark[c.up] = mark[c.right] = mark[c.down] = mark[c.left] = mark[c.center] = 1;

    int x;

    for(int i = 1 ; i < D ; i++){
        if(!mark[i]){
            x = i;
            break;
        }
    }

    // printf("x = %d\n", x);

    Dice d = c;

    if(dir == 'U'){
        d.up = d.center;
        d.center = d.down;
        d.down = x;
    }else if(dir == 'L'){
        d.left = d.center;
        d.center = d.right;
        d.right = x;
    }else if(dir == 'D'){
        d.down = d.center;
        d.center = d.up;
        d.up = x;
    }else{
        d.right = d.center;
        d.center = d.left;
        d.left = x;
    }

    return d;
}

typedef pair< int, Dice > p2;
typedef pair<pii, p2>  state;

queue< state > q;
const int N = C * L + 1;
int dis[N][1 << N][1 << (D + 1)];
int vi[] = {-1, 0, 1, 0}, vj[] = {0, 1, 0, -1};
char dir[] = {'U', 'R', 'D', 'L'};

bool ok(int x, int y){
    return x >= 0 && x < L && y >= 0 && y < C;
}

bool ver(Dice ux){
    set< int > st;

    st.insert(ux.up), st.insert(ux.right), st.insert(ux.down), st.insert(ux.left), st.insert(ux.center);

    return st.size() == 5;
}

int bfs(int source, int state_s){
    while(!q.empty()){
        q.pop();
    }

    memset(dis, -1, sizeof dis);
    dis[source][state_s][0] = 0;

    Dice x = {5, 2, 6, 4, 1};

    q.push({{source, state_s}, {0, x}});
    // printf("comecei!\n");
    int cnt = 0;

    while(!q.empty()){
        int u = q.front().first.first;
        int state = q.front().first.second;
        int mask = q.front().second.first;
        Dice ux = q.front().second.second;

        cnt++;
        q.pop();
        // printf("aqiu! %d %d %d %d %d\n", ux.center, ux.up, ux.right, ux.down, ux.left);
        int l = u / C, c = u % C;

        for(int i = 0 ; i < C ; i++){
            int li = l + vi[i], ci = c + vj[i];

            if(ok(li, ci)){
                int v = li * C + ci;
                int stateg = state, maskg = mask;
                Dice d = rotate(dir[i], ux);

                if(stateg & (1 << v)){
                    if((maskg & (1 << d.center)) == 0){
                        stateg ^= (1 << v);
                        maskg |= (1 << d.center);
                    }
                }else if(maskg & (1 << d.center)){
                    stateg |= (1 << v);
                    maskg ^= (1 << d.center);
                }

                if(dis[v][stateg][maskg] == -1){
                    dis[v][stateg][maskg] = dis[u][state][mask] + 1;

                    if(stateg == 0){
                        cout << li << " " << ci << endl;
                        // printf("%d execucoes\n", cnt);
                        return dis[v][stateg][maskg];
                    }

                    q.push({{v, stateg}, {maskg, d}});
                }
            }
        }
    }

    return 1e9;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    
    scanf("%d", &t);

    while(t--){
        int start = 0;
        int state_s = 0;

        for(int i = 0 ; i < L ; i++){
            for(int j = 0 ; j < C ; j++){
                char c;

                scanf("\n%c", &c);

                if(c == 'X'){
                    state_s |= 1 << (i * C + j);
                }

                if(c == 'D'){
                    start = i * C + j;
                }
            }
        }
        
        // printf("comecei!\n");
        
        int d = bfs(start, state_s);

        if(d != 1e9){
            printf("%d\n", d);
        }else{
            printf("impossible\n");
        }
    }

    return 0;
}