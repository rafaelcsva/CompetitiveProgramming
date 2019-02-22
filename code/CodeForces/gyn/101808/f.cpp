#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1010);
ll fat[N];
ll cnt[N];
const ll mod = 7901LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = i * fat[i - 1];
        fat[i] %= mod;
    }    

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            int ai;

            scanf("%d", &ai);
            cnt[ai]++;
        }

        ll r = 1LL;

        for(int i = 0 ; i < N ; i++){
            r *= fat[cnt[i]];
            r %= mod;
        }

        printf("%lld\n", r);

        memset(cnt, 0LL, sizeof cnt);
    }

    return 0;
}