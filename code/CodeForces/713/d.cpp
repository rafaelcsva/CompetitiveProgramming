#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
map< ll, int > ver;

const int N = int(2e5) + 10;
ll a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll sum = 0LL;

        for(int i = 0 ; i < n + 2 ; i++){
            scanf("%lld", &a[i]);

            sum += a[i];
            ver[a[i]]++;
        }

        ll x = -1LL;
        int posum = -1LL;

        for(int i = 0 ; i < n + 2 ; i++){
            ll p = sum - 2LL * a[i];

            if(ver[p] >= 1 + (a[i] == p)){
                x = p;
                posum = i;
                break;
            }
        }

        if(x == -1LL){
            cout << -1 << "\n";
        }else{
            for(int i = 0 ; i < n + 2 ; i++){
                if(i == posum) continue;

                if(a[i] == x){
                    x = -1LL;
                }else{
                    cout << a[i] << " ";
                }
            }

            cout << "\n";
        }

        ver.clear();
    }

    return 0;
}