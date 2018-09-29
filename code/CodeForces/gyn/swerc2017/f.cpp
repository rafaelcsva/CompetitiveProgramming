//10, 08, 2018, 15:26:43 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll w, n;

    scanf("%lld", &w);
    scanf("%lld", &n);

    ll tot = 0;

    for(int i = 0 ; i < n ; i++){
        ll a, b;

        scanf("%lld %lld", &a, &b);

        tot += a * b;
    }

    printf("%lld\n", tot / w);

    return 0;
}