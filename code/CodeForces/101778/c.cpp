#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(1e6) + 10;
ll phi[N];

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main(){
    phi_1_to_n(N - 1);
    int t;

    scanf("%d", &t);

    while(t--){
        ll m;

        scanf("%lld", &m);

        printf("%lld\n", phi[m] * (m - 1LL));
    }

    return 0;
}