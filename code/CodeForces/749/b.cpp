#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int marked[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < m ; i++){
            int ai, bi, ci;

            scanf("%d %d %d", &ai, &bi, &ci);

            marked[bi] = 1;
        }

        int root = -1;
        for(int i = 1 ; i <= n ; i++){
            if(!marked[i]){
                root = i;
                break;
            }
        }

        assert(root != -1);

        for(int i = 1 ; i <= n ; i++){
            if(i == root){
                continue;
            }

            printf("%d %d\n", i, root);
        }

        for(int i = 1 ; i <= n ; i++){
            marked[i] = 0;
        }
    }
}