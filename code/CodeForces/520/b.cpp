//14, 11, 2018, 14:09:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6 + 10);
vector< ll > primes;
bool is_composite[N];

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(ll i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

vector< ll > deco;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();

    ll n;

    scanf("%lld", &n);

    if(n == 1){
        printf("1 0\n");
        return 0;
    }

    int bpt = 0;
    bool has_diff = false;
    ll tn = n;

    for(int i = 0 ; i < primes.size() ; i++){
        ll k = primes[i];

        if(k * k > n){
            break;
        }

        int tmp = 0;

        if(n % k == 0LL){
            deco.push_back(k);
        }

        while(n % k == 0LL){
            n /= k;
            tmp++;
        }

        if(bpt != 0 && bpt != tmp){
            has_diff = true;
        }

        bpt = max(bpt, tmp);
    }

    if(n != 1LL){
        if(bpt == 0){
            bpt = 1;
        }

        if(1 != bpt){
            has_diff = true;
        }

        deco.push_back(n);
    }

    if(bpt == 1){
        printf("%lld 0\n", tn);
        return 0;
    }

    int dig = 0;
    int pt = 1;

    while(pt < bpt){
        pt *= 2;
        dig++;
    }

    int cost = dig;

    if(pt != bpt || has_diff){
        cost++;
    }

    ll num = 1LL;

    for(int i = 0 ; i < deco.size() ; i++){
        // printf("%lld\n", deco[i]);
        num *= deco[i];
    }

    printf("%lld %d\n", num, cost);

    return 0;
}