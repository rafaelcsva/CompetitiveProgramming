#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
vector<int>graph[N];
int cor[N], t, h;
int mer[N];
int flag = 1;
int cur;

bool dfs(int x, int v){
    cor[x] = t;
    bool ver = false;

    for(int i = 0 ; i < graph[x].size() ; i++){
        if(graph[x][i] == cur)
            continue;

        if(cor[graph[x][i]] != t){
            if(graph[x][i] == v){
                ver = true;
                cor[graph[x][i]] = t;
                mer[x] = h;
            }else{
                if(dfs(graph[x][i], v)){
                    mer[graph[x][i]] = h;
                }
            }
        }else{
            if(graph[x][i] == v || mer[graph[x][i]] == h){

                flag = 0;
            }
        }
    }

    return ver;
}

int main() {
    int n, m, q;

    scanf("%d%d%d", &n, &m, &q);

    for(int i = 0 ; i < n ; i++){
        int a, b;

        scanf("%d%d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(t = 1, h = 2; t <= q ; t++, h++){
        int a, b;

        scanf("%d%d", &a, &b);

        cur = a;
        flag = 1;
        dfs(a, b);

        printf("%d\n", flag);
    }
    return 0;
}