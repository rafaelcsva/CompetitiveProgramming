//18, 08, 2018, 12:40:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
int taked[N];
int c[N];
int a[N];
int in[N];
int father[N];
int bel[N];
int run = 1;

int dfs(int u, int ft){
    taked[u] = run;

    bel[run] = u;
    father[u] = run;

    if(a[u] == u){
        return 0;
    }else{
        int v = a[u];

        if(taked[v] == run){
            return v;
        }else if(taked[v]){
            bel[run] = bel[father[v]];
        }else{
            int r = dfs(v, ft);

            if(r != 0){
                int x = bel[run];

                if(c[x] > c[u]){
                    bel[run] = u;
                }

                if(u == r){
                    return 0;
                }else{
                    return r;
                }
            }
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &c[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        if(!taked[i]){
            dfs(i, i);
            run++;
        }
    }

    set< int > st;

    for(int k = 1 ; k < run ; k++){
        st.insert(bel[k]);
    }

    int sum = 0;

    for(set< int >::iterator it = st.begin() ; it != st.end() ; it++){
        sum += c[*it];
    }

    printf("%d\n", sum);
    
    return 0;
}