#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5);
bool is_composite[N];
vector< int > primes;

void sieve(){
    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
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

    int t;

    cin >> t;

    while(t--){
        int a, b, k;

        cin >> a >> b >> k;

        if(k == 1 && ((a % b != 0) && (b % a) != 0 || (a == b))){
            cout << "No\n";
        }else{
            int cnta = 0;

            for(auto u: primes){
                if(u * u > a){
                    break;
                }

                while(a % u == 0){
                    cnta++;
                    a /= u;
                }
            }

            if(a != 1){
                cnta++;
            }

            int cntb = 0;

            for(auto u: primes){
                if(u * u > b){
                    break;
                }

                while(b % u == 0){
                    cntb++;
                    b /= u;
                }
            }

            if(b != 1){
                cntb++;
            }

            if(cnta + cntb >= k){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }

    return 0;
}