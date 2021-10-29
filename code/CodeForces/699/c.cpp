#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int sig[N];
int a[N];
int b[N];
int c[N];
stack< int > stc[N];
int ans[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        memset(sig + 1, -1, sizeof(int) * (n + 1));
        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &b[i]);

            if(a[i] != b[i]){
                stc[b[i]].push(i);
            }else{
                sig[a[i]] = i;
            }
        }

        for(int i = 1 ; i <= m ; i++){
            scanf("%d", &c[i]);
        }

        int lst = -1;
        bool ok = true;

        for(int i = m ; i >= 1 ; i--){
            if(stc[c[i]].size()){
                int u = stc[c[i]].top();
                stc[c[i]].pop();
                ans[i] = u;
                lst = u;
            }else{
                if(lst != -1){
                    ans[i] = lst;
                }else if(sig[c[i]] != -1){
                    ans[i] = sig[c[i]];
                    lst = sig[c[i]];
                }
                else{
                    ok = false;
                    break;
                }
            }
        }

        for(int i = 1 ; i <= n ; i++){
            if(stc[i].size()){
                ok = false;
            }
            while(stc[i].size())
                stc[i].pop();
        }

        if(ok){
            printf("YES\n");

            for(int i = 1 ; i <= m ; i++){
                printf("%d ", ans[i]);
            }

            printf("\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}