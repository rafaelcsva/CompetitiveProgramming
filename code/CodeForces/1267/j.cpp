#include <bits/stdc++.h>

using namespace std;

const int N = int(2e6) + 10;

bool mark[N];
int cnt[N];
vector< int > els;
int a[N];

bool test(int x){
    for(auto u: els){
        int r = cnt[u] % x;
        if(r > cnt[u] / x){
            return false;
        }
    }

    return true;
}

int get_ans(int x){
    int tot = 0;

    for(auto u: els){
        // printf("%d-%d\n", u, cnt[u]);
        tot += (cnt[u] + x - 1) / x;
    }

    return tot;
}

int main(){ 
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int mcnt = N;

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            cnt[a[i]]++;
    
            if(!mark[a[i]]){
                els.push_back(a[i]);
            }

            mark[a[i]] = true;
        }

        for(auto u: els){
            mcnt = min(cnt[u], mcnt);
        }

        int ans = 2;

        for(int i = 3 ; i <= mcnt + 10 ; i++){
            if(test(i - 1)){
                ans = max(ans, i);
            }
        }

        // printf("%d\n", mcnt);

        printf("%d\n", get_ans(ans));

        for(auto u: els){
            cnt[u] = mark[u] = 0;
        }

        els.clear();
    }

    return 0;
}