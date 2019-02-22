//30, 10, 2018, 22:08:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5;
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

    for(ll i = 2LL ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

class SimpleMathProblemDiv2{
    public:
        long long calculate(int X){
            sieve();

            ll tot = 0LL;
            ll t = ll(X);

            for(int i = 0 ; i < primes.size() ; i++){
                if(primes[i] > t){
                    break;
                }

                ll cur = primes[i];

                for(ll k = primes[i] ; k <= t ; k += primes[i]){
                    if(cur * primes[i] <= k){
                        cur *= primes[i];
                    }

                    tot += cur;
                }
            }

            return tot;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    SimpleMathProblemDiv2 test;

    cout << "r = " << test.calculate(8) << endl;

    return 0;
}