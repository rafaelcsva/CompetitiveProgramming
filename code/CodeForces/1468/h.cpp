#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int pref[N];
int b[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k, m;

        scanf("%d %d %d", &n, &k, &m);

        for(int i = 0 ; i < m ; i++){
            scanf("%d", &b[i]);
        }

        int r = n - m;

        if(r % (k - 1) != 0){
            printf("NO\n");
        }else{
            int ansi = 0;
            int aa = 0;
            int bb = 0;
            int ans = int(1e9);

            for(int i = 0 ; i < m ; i++){
                int bes = b[i] - (lower_bound(b, b + m, b[i]) - b + 1);
                int up = (n - b[i]) - (m - (upper_bound(b, b + m, b[i]) - b)); 
                // printf("%d %d\n", bes, up);

                if(abs(up - bes) < ans){
                    ans = abs(up - bes);
                    aa = max(up, bes);
                    bb = min(up, bes);
                    ansi = i;
                }
            }

            int x = (aa - bb) / (k - 1);
            aa -= x * (k - 1);

            if(aa != bb){
                int ra = k - 1;
                int rb = 0;

                while(aa - ra != bb - rb){
                    ra--;
                    rb++;
                }

                aa -= ra;
                bb -= rb;
            }

            if(aa > 0 && bb > 0){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }

    return 0;
}