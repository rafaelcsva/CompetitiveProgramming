//20, 06, 2018, 21:11:51 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

ll n;
const int N = int(1e5);
vector<ll>primes;
bool isComposite[N];

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

int count_coprime_numbers(ll n){
    ll tn = n;
    ll ans = n;

    for(int i = 0 ; i < primes.size() && primes[i] * primes[i] <= tn ; i++){
        ll k = primes[i];

        if(tn % k == 0LL){
            ans -= ans / k;

            while(tn % k == 0LL){
                tn /= k;
            }
        }
    }

    if(tn != 1LL){
        ans -= ans / tn;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    while(cin >> n){
        if(n == 0)
            break;
            
        cout << count_coprime_numbers(n) << endl;
    }    

    return 0;
}