#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
bool is_composite[N];

void sieve(){
    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }
}

int main(){
    sieve();
    int mx = 0;
    // printf("tofora\n");
    // fflush(stdout);

    for(int k = 1 ; k <= 25 ; k++){
        // printf("K: %d\n", k);
        int cnt = 0;
        int sum = 0;
        for(int i = 1 ; i <= 2 * k ; i++){
            // printf("%d ", __gcd(2 * i + 1, k + i * i));
            int x1 = i * i;
            int x2 = (i + 1) * (i + 1);
            // mx = max(mx, __gcd(2 * i + 1, k + i * i));
            // if(__gcd(2 * i + 1, k + i * i) == 2 * i + 1){
            //     cnt++;
            //     if(cnt == 2){
            //         // printf("%d on %d\n", k, i);
            //         mx += i;
                    
            //         if(cnt == 2)
            //             break;
            //     }
            // }
            // if(__gcd(2 * i + 1, k + i * i) != 1)
            printf("%d ", __gcd(2 * i + 1, k + i * i));
        }
        printf("| %d\n", k);
    }
    // printf("%d\n", mx);

    return 0;
}
