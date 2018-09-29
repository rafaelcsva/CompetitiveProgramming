//15, 08, 2018, 10:21:15 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    ll mina = 1e9, minb = 1e9, suma = 0LL, sumb = 0LL;

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
        suma += a[i];
        mina = min(mina, a[i]);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &b[i]);
        sumb += b[i];
        minb = min(minb, b[i]);
    }
    
    vector< int > idx;

    ll havea = 0LL, haveb = 0LL;
    ll sz = (n + 1) / 2;

    for(int i = 0 ; i < n ; i++){
        if(sz == 0){
            break;
        }

        ll tmp = sz - 1LL;

        if(a[i] + tmp * mina + havea > (suma / 2LL) && b[i] + tmp * minb + haveb > (sumb / 2LL)){
            idx.push_back(i + 1);
            havea += a[i];
            haveb += a[i];
            sz--;
        }
    }

    return 0;
}