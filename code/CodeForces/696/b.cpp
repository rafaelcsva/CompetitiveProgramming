#include <bits/stdc++.h>

using namespace std;

vector< int > primes;
const int N = int(1e5);
bool is_composite[N];

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
    sieve();

    int t;

    scanf("%d", &t);

    while(t--){
        int d;

        scanf("%d", &d);

        int g = 0;
        int num = 1;
        int st = 1;

        while(g < 2){
            st = *lower_bound(primes.begin(), primes.end(), st + d);
            num *= st;
            g++;
        }

        printf("%d\n", num);
    }

    return 0;
}