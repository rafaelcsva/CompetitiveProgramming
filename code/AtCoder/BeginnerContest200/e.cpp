#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(3e6) + 10;
ll dp[3][3 * N];
ll bit[3][3 * N];

int LSOne(int x){
    return x & (-x);
}

void update(int pos, ll add, ll bit[]){
    while(pos < N){
        bit[pos] += add;
        pos += LSOne(pos);
    }
}

ll query(int pos, ll bit[]){
    ll sum = 0LL;

    while(pos > 0){
        sum += bit[pos];
        pos -= LSOne(pos);
    }
    
    return sum;
}

ll rsq(int l, int r, ll bit[]){
    if(l > r){
        return 0LL;
    }

    return query(r, bit) - query(l - 1, bit);
}

int main(){
    ll n, k;

    cin >> n >> k;

    for(int i = 1 ; i <= n ; i++){
        dp[0][i] = 1LL;
        update(i, 1LL, bit[0]);
    }

    for(int k = 1 ; k < 3 ; k++){
        for(int i = 1 ; i <= (k + 1) * n ; i++){
            // dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k];
            dp[k][i] = rsq(max(i - n, 1LL), i - 1, bit[k - 1]);
            update(i, dp[k][i], bit[k]);
        }
    }

    ll s = 1LL;
    for(s = 3LL ; s <= 3LL * n ; s++){
        ll add = dp[2][s];

        if(add >= k){
            break;
        }

        // printf("minus %lld for %lld\n", dp[2][s], s);
        k -= add;
    }
    // printf("s is %lld, k is %lld\n", s, k);

    ll i;
    for(i = 1LL ; i <= s - 2LL ; i++){
        ll add = dp[1][s - i];

        if(add >= k){
            break;
        }
        // printf("minud %lld\n", add);

        k -= add;
    }

    ll j = k;
    ll K;

    for(j = 1 ; j <= n ; j++){
        K = s - i - j;

        if(K <= n){
            k--;
        }
        if(k == 0){
            break;
        }
    }

    cout << i << " " << j << " " << K << endl;

    return 0;
}