//31, 07, 2018, 12:35:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1e5 + 10;
ll save[N];
ll a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    scanf("%d %d", &n, &m);

    ll sum = 0LL;
    
    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &a[i], &b[i]);

        save[i] = a[i] - b[i];
        sum += a[i];
    }

    int taked = 0;

    sort(save, save + n, greater<ll>());

    for(int i = 0 ; i < n ; i++){
        if(sum <= m)
            break;

        taked++;
        sum -= save[i];
    }

    if(sum <= m)
        printf("%d\n", taked);
    else
        printf("-1\n");
        
    return 0;
}