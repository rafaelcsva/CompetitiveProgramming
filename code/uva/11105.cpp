//21, 11, 2018, 18:50:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e6);
bool is_composite[N];
int pre[N];
vector< int > primes;

int f(int i){
    return i * 4 + 1;
}

void sieve(){
    for(int k = 1 ; f(k) * f(k) < N ; k++){
        int i = f(k);
        // printf("%d\n", i);

        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i] && (i % 4) == 1){
            primes.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h;

    sieve();

    for(int i = 1 ; f(i) < N ; i++){
        int k = f(i);
        bool ok = false;

        if(is_composite[k]){
            for(int j = 0 ; j < primes.size() ; j++){
                int ti = primes[j];

                if(ti > (k + ti - 1) / ti){
                    break;
                }

                if(k % ti == 0){
                    int other = k / ti;

                    if(!is_composite[other]){
                        ok = true;
                    }

                    break;
                }
            }
        }

        if(ok){
            pre[k] = 1;
        }
    }   

    for(int i = 1 ; i < N ; i++){
        pre[i] += pre[i - 1];
    }

    while(scanf("%d", &h) != EOF){
        if(h == 0)
            break;

        printf("%d %d\n", h, pre[h]);
    }
    
    return 0;
}