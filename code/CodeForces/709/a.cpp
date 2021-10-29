#include <bits/stdc++.h>

using namespace std;

typedef pair< vector< int >, int > pvi;

const int K = int(1e5) + 10;
vector< pvi > con[K];
int cnt[K];
int ans[K];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        int half = (m + 1) / 2;

        for(int i = 1 ; i <= m ; i++){
            int ki;

            vector< int > tmp;

            scanf("%d", &ki);

            for(int j = 0 ; j < ki ; j++){
                int xi;

                scanf("%d", &xi);

                tmp.push_back(xi);
            }

            con[ki].push_back({tmp, i});
        }

        bool flag = true;

        for(int j = 1 ; j <= n ; j++){
            for(auto pv: con[j]){
                bool ok = false;
                for(auto e: pv.first){
                    if(cnt[e] < half){
                        ok = true;
                        cnt[e]++;
                        ans[pv.second] = e;
                        break;
                    }
                }

                if(!ok){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }

        if(!flag){
            printf("NO\n");
        }else{
            printf("YES\n");
            for(int i = 1 ; i <= m ; i++){
                printf("%d ", ans[i]);
            }

            printf("\n");
        }

        for(int i = 0 ; i <= n ; i++){
            con[i].clear();
            cnt[i] = 0;
        }
    }

    return 0;
}