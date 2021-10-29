#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int l[N], r[N];

int main(){
    int n;

    scanf("%d", &n);

    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        int ti;

        scanf("%d %d %d", &ti, &l[i], &r[i]);
        l[i] *= 2LL;
        r[i] *= 2LL;

        if(ti == 2){
            r[i]--;
        }else if(ti == 3){
            l[i]++;
        }else if(ti == 4){
            r[i]--;
            l[i]++;
        }

        for(int j = 0 ; j < i ; j++){
            int li = max(l[j], l[i]);
            int ri = min(r[j], r[i]);

            if(li <= ri){
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}