#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int a[N];
int idx[N];
vector< int > op;
int marked[N];

void mswap(int i, int j){
    swap(a[i], a[j]);
    // printf("%d %d\n", a[i], a[j]);
    idx[a[i]] = i;
    idx[a[j]] = j;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        idx[a[i]] = i;
    }

    for(int i = 1 ; i <= n ; i++){
        int pos = idx[i];
        int val = i;

        for(int d = pos - 1 ; d >= val ; d--){
            if(marked[d]){
                printf("-1\n");
                return 0;
            }

            op.push_back(d);
            marked[d] = 1;
            mswap(d, d + 1);
        }
    }

    if(op.size() != n - 1){
        printf("-1\n");
        return 0;
    }

    for(int u: op){
        printf("%d\n", u);
    }

    return 0;
}