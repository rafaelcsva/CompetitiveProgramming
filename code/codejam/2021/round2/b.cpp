#include <bits/stdc++.h>

using namespace std;

map< pair< int, int >, int > mp;

int solve(int r, int mult){
    if(r == 0) return 0;

    if(mp.count({r, mult}) != 0){
        return mp[{r, mult}];
    }

    int ans = 0;
    for(int i = 2 ; i <= r / mult ; i++){
        int re = r - mult * i;

        if(re % (mult * i) == 0){
            ans = max(1 + solve(re, mult * i), ans);
        }
    }

    return mp[{r, mult}] = ans;
}

const int N = int(1e6) + 10;
int tans[N];

int main(){
    memset(tans, -1, sizeof tans);

    vector< int > res;
    int q = 2;
    for(int i = 1 ; i <= 20 ; i++){
        res.push_back(q - 1);
        q = q * 2;
    }

    int t;

    scanf("%d", &t);

    int test = 1;

    // printf("p: %d\n", upper_bound(res.begin(), res.end(), 1024) - res.begin());

    while(t--){
        int n;

        scanf("%d", &n);

        int ans = 0;

        for(int i = 1 ; i * i <= n ; i++){
            if(n % i == 0){
                if(i >= 3){
                    int re = n / i;

                    if(tans[re] != -1){
                        ans = max(ans, tans[re]);
                    }else{
                        tans[re] = 1 + solve(re - 1, 1);

                        ans = max(ans, tans[re]);
                    }

                    // if(pos == 3){
                    //     printf("%d %d\n", i, re);
                    // }
                }

                int r = n / i;
                if(r >= 3){
                    int re = n / r;

                    if(tans[re] != -1){
                        ans = max(ans, tans[re]);
                    }else{
                        tans[re] = 1 + solve(re - 1, 1);

                        ans = max(ans, tans[re]);
                    }
                }
            }
        }

        printf("Case #%d: %d\n", test++, ans);
    }

    return 0;
}