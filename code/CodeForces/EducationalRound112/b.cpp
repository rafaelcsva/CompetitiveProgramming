#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

double dist(ll x1, ll y1, ll x2, ll y2){
    return hypot(x2 - x1, y2 - y1);
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll W, H;

        scanf("%lld %lld", &W, &H);

        ll x1, y1, x2, y2;

        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

        ll w, h;
        ll wu, hu;

        scanf("%lld %lld", &w, &h);

        wu = x2 - x1;
        hu = y2 - y1;

        if(h + hu > H && w + wu > W){
            printf("-1\n");
        }else{
            if(y1 >= h || H - y2 >= h || x1 >= w || W - x2 >= w){
                printf("0\n");
            }else{
                ll minDis = 1e9;

                if(h + hu <= H){
                    minDis = min(h - y1, h - (H - y2));
                }

                if(w + wu <= W){
                    minDis = min({minDis, w - x1, w - (W - x2)});
                }

                printf("%lld\n", minDis);
            }
        }
    }

    return 0;
}