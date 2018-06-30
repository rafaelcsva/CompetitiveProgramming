#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5);
bool isComposite[N];
vector<ll>primes;

int sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!isComposite[i]){
            for(int j = i * i ; j < N ; j += i){
                isComposite[j] = true;
            }
        }
    }

    for(ll i = 2 ; i < N ; i++){
        if(!isComposite[i]){
            primes.push_back(i);
        }
    }
}

int sum_of_divisors(ll n){
    ll cnt = 1LL;

    for(int i = 0 ; i < primes.size() && primes[i] * primes[i] <= n ; i++){
        ll r = 0LL;
        ll k = primes[i];
        
        while(n % k == 0LL){
            n /= k;
            r++;
        }

        cnt *= (r + 1LL);
    }

    if(n != 1LL){
        cnt *= 2LL;
    }

    return cnt;
}
int main(){
    sieve();

    ll n;

    while(cin >> n){
        if(n == 0){
            break;
        }

        ll cnt = sum_of_divisors(n);
        
        if(cnt % 2LL == 0LL){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }

    return 0;
}