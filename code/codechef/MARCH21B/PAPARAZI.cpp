#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(5e5) + 10;
int nxt1[N], nxt2[N];
int h[N];
priority_queue< pair< int, int > > pq;

int go(int i, ll x, ll y, int nxt[]) {
    // printf("%d %lld %d\n", i, x, nxt[i]);

    // fflush(stdout);
    // return i;
    if(nxt[i] == i){
        return i;
    }

    ll y1 = y + h[nxt[i]] - h[i];
    ll x1 = x + abs(nxt[i] - i);

    if(y1 * x >= y * x1){
        return nxt[i] = go(nxt[i], x1, y1, nxt);
    }else {
        return i;
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &h[i]);
            nxt1[i] = nxt2[i] = i;
        }

        for(int i = 0 ; i < n ; i++){
            while(!pq.empty()){
                auto u = pq.top();

                if(-u.first >= h[i]){
                    break;
                }

                pq.pop();
            }

            if(!pq.empty())
                nxt1[i] = pq.top().second;
            pq.push({-h[i], i});
        }

        while(!pq.empty()){
            pq.pop();
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!pq.empty()){
                auto u = pq.top();

                if(-u.first >= h[i]){
                    break;
                }

                pq.pop();
            }

            if(!pq.empty())
                nxt2[i] = -pq.top().second;
            pq.push({-h[i], -i});
        }

        // printf("aqui!\n");
        // fflush(stdout);
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            // printf("%d %d %d\n", i, nxt1[i], nxt2[i]);
            ans = max(ans, i - go(i, 0, 0, nxt1));
            // printf("%d %d %d\n", i, nxt1[i], nxt2[i]);
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            ans = max(ans, go(i, 0, 0, nxt2) - i);
        }

        printf("%d\n", ans);

        while(!pq.empty()){
            pq.pop();
        }
    }

    return 0;
}
