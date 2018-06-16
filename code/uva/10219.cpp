//05, 06, 2018, 21:18:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int n, k;
    
    while(scanf("%d %d", &n, &k) != EOF){

        ld sum = 0.0L;

        for(ll i = n ; i > n - k ; i--){
            sum += log10(i);
        }

        for(ll i = 1 ; i <= k ; i++){
            sum -= log10(i);
        }

        ll d = floor(sum + 1);

        printf("%lld\n", d);
    }

    return 0;
}