//29, 12, 2018, 12:36:39 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6 + 20);
ll pref_year[N];
ll pref_month[N];
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);
    
    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &a[i]);

            pref_month[i] = a[i] + pref_month[i - 1];
        }

        int yb, mb;
        ll db;

        scanf("%d %d %lld", &yb, &mb, &db);

        int yc, mc;
        ll dc;

        scanf("%d %d %lld", &yc, &mc, &dc);   

        assert(yb <= yc);

        for(int i = 2 ; i <= yc ; i++){
            ll add = pref_month[n];

            if((i - 1) % 4 == 0){
                add++;
            }

            pref_year[i] = pref_year[i - 1] + add;
        }

        ll days_past_b = pref_year[yb] + pref_month[mb - 1] + db;
        ll days_past_c = pref_year[yc] + pref_month[mc - 1] + dc;

        assert(days_past_c - days_past_b + 1LL >= 1LL);
        
        printf("%lld\n", days_past_c - days_past_b + 1LL);
    }

    return 0;
}