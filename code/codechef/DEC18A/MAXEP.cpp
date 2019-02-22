//07, 12, 2018, 08:42:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int step = 1e4;

int main(){
    int n, c;

    scanf("%d %d", &n, &c);

    int last = 1;
    int lim = n;
    int cost = 1000;

    do{
        int cur = last;
        bool need_fix = false;
        // printf("step = %d\n", step);

        while(cur <= lim){
            assert(cost > 0);
            printf("1 %d\n", cur);
            cost--;

            fflush(stdout);

            int xi;

            scanf("%d", &xi);

            if(xi == 1){
                if(step == 1){
                    last = cur;
                }

                need_fix = true;
                break;
            }

            last = cur;
            cur += step;
        }
        lim = min(n, cur);
        step /= 10;

        if(need_fix && step != 0){
            cost -= c;
            assert(cost > 0);
            printf("2\n");
            fflush(stdout);
        }
    }while(step != 0);

    printf("3 %d\n", last);
    fflush(stdout);

    return 0;
}