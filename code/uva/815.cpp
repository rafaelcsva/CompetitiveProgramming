//29, 08, 2018, 14:49:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< ll > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int test = 1;
    bool print = false;

    while(scanf("%d %d", &n, &m) != EOF){
        if(print){
            printf("\n");
        }

        print = true;
        
        if(n == 0)
            break;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ll x;

                scanf("%lld", &x);

                v.push_back(x);
            }
        }

        sort(v.begin(), v.end());
        
        ll vol;

        scanf("%lld", &vol);

        ll cnt = 1;
        ll last = v[0];

        for(int i = 1 ; i < v.size() ; i++){
            ll diff = v[i] - v[i - 1];

            if(diff * 100LL * cnt >= vol){
                break;
            }

            last = v[i];
            vol -= diff * 100LL * cnt;
            cnt++;
        }

        printf("Region %d\n", test++);
        printf("Water level is %.2Lf meters.\n", ld(vol) / ld(100 * cnt) + last);
        printf("%.2Lf percent of the region is under water.\n", (ld(cnt) / ld(v.size())) * 100.0L);

        v.clear();
    }

    return 0;
}