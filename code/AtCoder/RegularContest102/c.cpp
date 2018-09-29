//01, 09, 2018, 09:06:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
ll cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1 ; i <= n ; i++){
        cnt[i % k]++;
    }

    ll all = 0LL;

    for(int i = 1 ; i <= n ; i++){
        int need = k - (i % k);
        need %= k;

        if(((2 * need) % k) == 0){
            all += cnt[need] * cnt[need];
        }
    }

    printf("%lld\n", all);
    
    return 0;
}