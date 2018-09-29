//18, 08, 2018, 10:25:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
vector< ll > a[N];
ld mean[N];
ld dp[N];
bool used[N];
ld EPS = 0.00000000000001L;
int n;

ld compute(int k){
    if(used[k]){
        return dp[k];
    }

    used[k] = true;

    ld sum = 0.0L;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < a[i].size() ; j++){
            sum += fabs(mean[k] - a[i][j]);
        }
    }

    dp[k] = sum;
    
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int m;
        
        scanf("%d", &m);

        ll sum = 0LL;

        for(int j = 0 ; j < m ; j++){
            ll x;

            scanf("%lld", &x);
            a[i].push_back(x);

            sum += x;
        }
        
        mean[i] = ld(sum) / ld(m);
    }

    ld best = 1e18;

    for(int it = 0 ; it < 5000 ; it++){
        int idx = rand() % n;

        ld v = compute(idx);

        if(best - v > EPS){
            best = v;
        }
    }

    printf("%.6Lf\n", best);

    return 0;
}