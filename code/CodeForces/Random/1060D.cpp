//04, 10, 2018, 15:39:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5);
ll a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + n);

    ll tot = n;

    for(int i = 0 ; i < n ; i++){
        tot += max(a[i], b[i]);
    }

    printf("%lld\n", tot);

    return 0;
}