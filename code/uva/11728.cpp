//20, 06, 2018, 21:41:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e4);
vector<ll>primes;
bool isComposite[N];
ll answer[N];
const ll LIM = 1000;

void sieve(){
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

ll fast_pow(ll n, int x){
    if(x == 0)
        return 1;

    if(x == 1)
        return n;

    ll a = fast_pow(n, x / 2);

    a *= a;

    if(x & 1)
        a *= n;

    return a;
}

ll sum_divisors_of(ll n){
    ll r = 1LL;
    
    for(int i = 0 ; i < primes.size() && primes[i] * primes[i] <= n ; i++){
        ll k = primes[i];

        int qtd = 0;

        while(n % k == 0LL){
            n /= k;
            qtd++;
        }
        
        r *= (fast_pow(k, qtd + 1) - 1LL) / (k - 1LL);
        if(r < 0LL || r > LIM){
            return LIM + 1;
        }
    }

    if(n != 1LL){
        r *= (fast_pow(n, 2) - 1LL) / (n - 1LL);
    }

    return r;
}

void compute(){
    for(int i = 1 ; i < N ; i++){
        ll sum = sum_divisors_of(i);

        if(sum <= LIM){
            answer[sum] = i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    compute();

    int n;
    int test = 1;

    while(cin >> n){
        if(n == 0)
            break;
            
        cout << "Case " << test++ << ": ";
        
        if(answer[n]){
            cout << answer[n] << endl;
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}