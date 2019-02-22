//28, 09, 2018, 21:50:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5 + 10;
const int B = 64;
ll a[N];
ll sum_odd, sum_even;
ll pre[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);

        a[i] = __builtin_popcountll(a[i]);
    }

    ll carry = 0LL;
    ll cnt = 0LL;
    sum_even = 1;

    for(int i = 1 ; i <= n ; i++){

        carry += a[i];

        if(i != 1){
            if(carry & 1){
                cnt += sum_odd;
                // printf("+%lld\n", sum_odd);
                for(int j = 0 ; j < B ; j++){
                    if(i - j - 1 < 0){
                        break;
                    }
                    // printf("j = %d\n", i);
                    if((pre[i - j - 1] & 1LL) == 0)
                        continue;
                    
                    ll take = 0LL;
                    ll best = 0;
                    
                    for(int k = i ; k >= i - j ; k--){
                        best = max(best, a[k]);
                        take += a[k];
                    }

                    // printf("take = %lld, best = %lld %d\n", take, best, j + 1);
                    take -= best;
                    // printf("take = %lld, best = %lld\n", take, best);

                    if(take < best){
                        cnt--;
                    }
                }
            }else{
                cnt += sum_even;
                // printf("+%lld %lld\n", sum_even, pre[i]);
                for(int j = 0 ; j < B ; j++){
                    if(i - j - 1 < 0){
                        break;
                    }

                    if((pre[i - j - 1] & 1LL) == 1)
                        continue;
                    
                    ll take = 0LL;
                    ll best = 0;
                    
                    for(int k = i ; k >= i - j ; k--){
                        best = max(best, a[k]);
                        take += a[k];
                    }

                    // printf("take = %lld, best = %lld %d\n", take, best, j + 1);
                    take -= best;
                    // printf("take = %lld, best = %lld\n", take, best);

                    if(take < best){
                        // if(i - j - 1 == 0){
                        //     printf("i = %d\n", i);
                        // }else{
                        //     printf("%d\n", i);
                        // }
                        cnt--;
                    }
                }
            }
        }
        pre[i] += a[i] + pre[i - 1];

        if(pre[i] & 1){
            sum_odd++;
        }else{
            sum_even++;
        }
    }

    printf("%lld\n", cnt);

    return 0;
}