//02, 06, 2018, 07:51:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e6 + 10);
int mark[N];
ll box[N];
ll v[N];
vector<ll>primes;
bool isPrime[N];

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!isPrime[i]){
            for(int j = i + i ; j < N ; j += i){
                isPrime[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    for(int i = 0 ; i < primes.size() ; i++){
        cout << primes[i] << endl;
    }
    
    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        int n;

        cin >> n;
        bool have1 = false;
        
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
            
            if(v[i] == 1){
                have1 = true;
            }
        }

        sort(v, v + n);
        
        if(have1) {
            cout << n << endl;
            continue;
        }

        ll sum = 0LL;

        for(int i = 0 ; i < n ; i++){
            ll best = v[i];
            
            ll tmp = v[i];
            
            for(int j = 0 ; j < primes.size() ; j++){
                if(primes[j] * primes[j] > v[i]){
                    break;
                }

                if(tmp % primes[j] == 0){
                    if(mark[primes[j]] != test){
                        mark[primes[j]] = test;
                        box[primes[j]] = v[i];
                    }
                    
                    best = min(best, box[primes[j]]);

                    while(tmp % primes[j] == 0){
                        tmp /= primes[j];
                    }
                }
            }

            if(tmp != 1){
                if(mark[tmp] != test){
                    mark[tmp] = test;
                    box[tmp] = v[i];
                }
                
                best = min(best, box[tmp]);
            }

            sum += best;
        }

        cout << sum << endl;
    }

    return 0;
}