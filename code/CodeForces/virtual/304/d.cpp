#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = (int) 5e6 + 100;
int isPrime[N];
vector<int>primes;
ll calc[N];

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!isPrime[i]){
            primes.push_back(i);
            
            for(int j = i + i ; j < N ; j += i){
                isPrime[j] = 1;
            }
        }
    }
}

ll solve(int x, int j){
    if(x == 1){
        return calc[x] = 0;
    }

    if(!isPrime[x]){
        return calc[x] = 1LL;
    }

    if(calc[x] != 0){
        return calc[x];
    }

    calc[x] = 1;

    for(int i = j ; i < primes.size() ; i++){
        if(x % primes[i] == 0){
            calc[x] = 1LL + solve(x / primes[i], i);
            break;
        }
    }

    return calc[x];
}

int t, a, b;
int i;

int main(){
    sieve();

    for(int i = 1 ; i <= N - 100 ; i++){
        if(i == 1){
            calc[i] = 0;
        }
        else if(!isPrime[i]){
            calc[i] = 1LL;
        }else{
            for(int j = 0 ; j < primes.size() ; j++){
                if(i % primes[j] == 0){
                    calc[i] = 1 + calc[i / primes[j]];
                    break;
                }
            }
        }
    }

    for(int i = 1 ; i <= N - 100 ; i++){
        calc[i] += calc[i - 1];
    }

    scanf("%d", &t);

    while(t--){
        scanf("%d%d", &a, &b);

        printf("%lld\n", calc[a] - calc[b]);
    }

    return 0;
}