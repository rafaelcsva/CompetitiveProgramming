#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e6) + 10;
ll pref[N], suf[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        string s;

        cin >> s;

        ll acc = 0LL;
        pref[0] = suf[n + 1] = 0LL;

        for(int i = 0 ; i < n ; i++){
            pref[i + 1] = pref[i];

            if(s[i] == '.'){
                pref[i + 1] += acc;
            }else{
                acc++;
            }
            // printf("%lld\n", pref[i + 1]);
        }

        acc = 0LL;

        for(int i = n - 1 ; i >= 0 ; i--){
            suf[i + 1] = suf[i + 2];

            if(s[i] == '.'){
                suf[i + 1] += acc;
            }else{
                acc++;
            }
        }
        ll best = ll(1e18);

        for(int i = 0 ; i <= n ; i++){
            best = min(best, pref[i] + suf[i + 1]);
        }

        printf("%lld\n", best);
    }

    return 0;
}