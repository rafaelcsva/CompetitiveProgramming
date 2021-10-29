#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
vector< int > primes;
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
        int x, y;

        scanf("%d %d", &x, &y);

        int cnt = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
        printf("%d %d\n", cnt, y);
        if(cnt <= y){
            printf("Chef\n");
        }else{
            printf("Divyam\n");
        }
    }

    return 0;
}