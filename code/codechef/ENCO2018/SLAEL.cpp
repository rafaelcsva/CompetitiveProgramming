//26, 10, 2018, 13:31:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 10;
ll pref_qtd[N], pref[N];
ll a[N];
set< ll > st;

int b1(int lo, int hi){
    int r = -1;
    int ini = lo;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        ll q = pref_qtd[mid] - pref_qtd[ini - 1];

        if(q == 1LL){
            return mid;
        } 

        if(q == 0){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    return r;
}

int b2(ll lo, ll hi, ll param){
    int r = -1;
    int ini = lo;

    while(lo <= hi){
        ll mid = (lo + hi) / 2LL;
        ll guys = pref_qtd[mid] - pref_qtd[ini - 1];
        ll q = pref[mid] - pref[ini - 1];

        if(q != guys * param){
            hi = mid - 1;
        }else{
            r = mid;
            lo = mid + 1;
        }
    }

    // printf("r: %d\n", r);

    return r - ini + 1LL;
}

int get_best(int i, int n){
    int ind = b1(i, n);

    if(ind == -1){
        return 0;
    }
    // printf("%d eh %d val = %lld\n", i, ind, pref[ind] - pref[i - 1]);

    return b2(i, n, pref[ind] - pref[i - 1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        ll k;

        scanf("%d %lld", &n, &k);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &a[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            if(a[i] > k){
                pref_qtd[i] = 1LL;
                pref[i] = a[i];
            }

            pref_qtd[i] += pref_qtd[i - 1];
            pref[i] += pref[i - 1];
        }

        int best = 0;
        
        for(int i = 1 ; i <= n ; i++){
            best = max(best, get_best(i, n));
        }

        printf("%d\n", best);

        memset(pref, 0LL, sizeof pref);
        memset(pref_qtd, 0LL, sizeof pref_qtd);
    }
    
    return 0;
}