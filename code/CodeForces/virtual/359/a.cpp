//09, 08, 2018, 11:01:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;

    scanf("%lld %lld", &n, &k);

    ll dis = 0;

    for(int i = 0 ; i < n ; i++){
        char c;
        int amount;

        scanf("\n%c %d", &c, &amount);

        if(c == '-'){
            if(k >= amount){
                k -= amount;
            }else{
                dis++;
            }
        }else{
            k += amount;
        }
    }

    printf("%lld %lld\n", k, dis);

    return 0;
}