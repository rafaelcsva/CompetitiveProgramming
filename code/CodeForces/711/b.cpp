#include <bits/stdc++.h>

using namespace std;

const int N = int(2e7) + 10;
int cnt[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, w;

        scanf("%d %d", &n, &w);

        for(int i = 0 ; i < n ; i++){
            int wi;

            scanf("%d", &wi);

            cnt[wi]++;
        }

        bool found = true;
        int h = 0;

        while(found){
            found = false;
            int tw = w;
            // printf("asdf\n");

            for(int d = 20 ; d >= 0 ; d--){
                int e = 1 << d;
                // printf("%d\n", e);

                while(e <= tw && cnt[e]){
                    // printf("%lld\n", tw);
                    cnt[e]--;
                    tw -= e;
                    found = true;
                }
            }

            if(found){
                h++;
            }
        }

        printf("%d\n", h);

        for(int d = 1 ; d < N ; d *= 2){
            cnt[d] = 0;
        }
    }
    return 0;
}