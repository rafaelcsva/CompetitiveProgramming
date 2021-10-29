#include <bits/stdc++.h>

using namespace std;

int comp(int x, int k){
    int num = 0;
    int b = 1;

    while(x > 0){
        int r = x % k;
        
        num += ((k - r) % k) * b;
        x /= k;
        b *= k;
    }

    return num;
}

int xxor(int a, int b, int k){
    int num = 0;
    int p = 1;

    while(a || b){
        int r1 = a % k;
        int r2 = b % k;

        r1 = (r1 + r2) % k;
        num += r1 * p;
        p *= k;

        a /= k;
        b /= k;
    }

    return num;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        int x = 0;
        // int init = 3;
        // printf("%d\n", xxor(1, comp(7, k), k));
        int init = 1;

        for(int i = 0 ; i < n ; i++){
            int test = i;

            if(i > 0){
                // printf("%d and %d, %d\n", i - 1, comp(i - 1, k), test, test ^ (i - 1));
                assert(xxor(test, comp(test, k), k) == 0);
                test = xxor(test, comp(i - 1, k), k);
            }
            printf("%d\n", test);
            fflush(stdout);

            // printf("i am %d\n", init);
            int r;

            scanf("%d", &r);

            if(r == 1){
                break;
            }

            // assert(init != test);
            init = xxor(test, init, k);

            assert(r != -1);
        }
    }

    return 0;
}