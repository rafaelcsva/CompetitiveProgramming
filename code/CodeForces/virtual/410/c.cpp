//15, 08, 2018, 10:46:51 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll g = 0;

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
        g = __gcd(g, a[i]);
    }

    // int d, b;

    // scanf("%d %d", &d, &b);

    // while(true){
    //     int next;

    //     scanf("%d", &next);

    //     if(next == 1){
    //         int x1 = d, x2 = b;

    //         d = x1 - x2;
    //         b = x1 + x2;

    //         printf("%d, %d\n", d, b);
    //     }else{
    //         break;
    //     }
    // }
    int op = 0;

    if(g == 1){
        int i = 0;

        while(i < n - 1){
            if(a[i] % 2 != 0){
                ll x1, x2;
                
                while(a[i] % 2 != 0 || a[i + 1] % 2 != 0){
                    x1 = a[i], x2 = a[i + 1];

                    a[i] = x1 - x2;
                    a[i + 1] = x1 + x2;
                    op++;
                }
                
                i += 2;
            }else
                i++;
        }

        if(a[n - 1] % 2 != 0){
            ll x1 = a[n - 2];
            ll x2 = a[n - 1];

            a[n - 2] = x1 - x2;
            a[n - 1] = x1 + x2;
            op++;

            if(a[n - 2] != 0 || a[n - 1] % 2 != 0){
                x1 = a[n - 2], x2 = a[n - 1];

                a[n - 1] = x1 + x2;
                a[n - 2] = x1 - x2;
                op++;
            }
        }
    }
    
    printf("YES\n%d\n", op);

    return 0;
}