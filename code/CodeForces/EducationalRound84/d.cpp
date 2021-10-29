#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N], c[N], tmp[N], tmp2[N];
int test_num = 1;
int marked[N];

bool test(int st, int u){
    if(u == st){
        return true;
    }

    if(marked[u] == test_num){
        return false;
    }
    marked[u] = test_num;

    if(c[st] != c[u]){
        return false;
    }

    return test(st, tmp[u]);
}

bool ident(int n){
    test_num++;

    for(int i = 1 ; i <= n ; i++){
        marked[i] = test_num;
        if(test(i, tmp[i])){
            return true;
        }
    }

    return false;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
            tmp[i] = a[i];
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &c[i]);
        }

        int steps = 0;

        while(!ident(n)){
            for(int i = 1 ; i <= n ; i++){
                tmp2[i] = tmp[a[i]];
            }
            for(int i = 1 ; i <= n ; i++){
                tmp[i] = tmp2[i];
            }
            steps++;
        }

        printf("%d\n", steps + 1);
    }

    return 0;
}