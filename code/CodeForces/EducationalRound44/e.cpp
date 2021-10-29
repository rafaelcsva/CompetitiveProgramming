#include <bits/stdc++.h>

using namespace std;

const int N = int(5e5) + 10;
int a[N];
int bst[N];
int dp[N];

int LSOne(int x){
    return x & (-x);
}

int query(int x){
    int ans = 0;

    while(x > 0){
        ans += bst[x];
        x -= LSOne(x);
    }

    return ans;
}

void update(int x){
    while(x < N){
        bst[x]++;
        x += LSOne(x);
    }
}

int rsq(int l, int r){
    if(l > r){
        return 0;
    }

    return query(r) - query(l - 1);
}

int main(){
    int n, k, d;

    scanf("%d %d %d", &n, &k, &d);

    for(int i = 2 ; i <= n + 1 ; i++){
        scanf("%d", &a[i]);
    }

    sort(a + 2, a + 2 + n);

    update(1);

    int l = 2;

    for(int i = 2 ; i <= n + 1 ; i++){
        while(a[i] - a[l] > d){
            l++;
        }

        int o = i - k + 1;

        dp[i] = (rsq(l - 1, o - 1) > 0);
    
        if(dp[i]){
            update(i);
        }
    }

    if(dp[n + 1]){
        printf("YES\n");
    }else{
        printf("NO\n");
    }


    return 0;
}