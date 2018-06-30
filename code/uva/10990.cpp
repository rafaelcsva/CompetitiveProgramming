//23, 06, 2018, 19:54:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(2e6 + 10);
ll steps[N], phi[N], pref[N];
vector< ll > primes;
bool isComposite[N];

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!isComposite[i]){
            for(int j = i * i ; j < N ; j += i){
                isComposite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!isComposite[i]){
            primes.push_back(i);
        }
    }
}

void process(ll n){
    ll &ans = phi[n];
    ans = n;

    for(ll i = 0 ; i < primes.size() && primes[i] * primes[i] <= n ; i++){
        ll k = primes[i];

        if(n % k == 0){
            ans -= ans / k;

            while(n % k == 0)
                n /= k;
        }    
    }

    if(n != 1){
        ans -= ans / n;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    
    for(ll i = 1 ; i < N ; i++){
        process(i);
    }

    for(int i = 2 ; i < N ; i++){
        steps[i] = 1LL + steps[phi[i]];

        pref[i] = steps[i] + pref[i - 1];
    }

    int t;

    scanf("%d", &t);
    
    for(int i = 0 ; i < t ; i++){
        int n, m;

        scanf("%d %d", &n, &m);

        printf("%lld\n", pref[m] - pref[n - 1]);
    }
    
    return 0;
}