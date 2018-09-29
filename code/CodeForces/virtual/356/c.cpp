//17, 07, 2018, 12:53:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
const int N = 101;
bool is_composite[N];
vector<int>primes;

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i * i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();

    int cnt_divisors = 0;
    int prime_divisor = 0;

    for(int i = 0 ; primes[i] * primes[i] <= N ; i++){
        cout << primes[i] << endl;

        string s;

        cin >> s;

        if(s == "yes"){
            prime_divisor = primes[i];
            cnt_divisors++;
            cout << primes[i] * primes[i] << endl;

            cin >> s;

            if(s == "yes"){
                cnt_divisors++;
            }
        }
        
        if(cnt_divisors >= 2){
            cout << "composite" << endl;
            return 0;
        }
    }

    if(prime_divisor == 0){
        cout << "prime" << endl;
        return 0;
    }
    
    for(int i = 4 ; i < primes.size() ; i++){
        if(primes[i] * prime_divisor > N){
            break;
        }

        cout << primes[i] * prime_divisor << endl;

        string s;

        cin >> s;

        if(s == "yes"){
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;

    return 0;
}