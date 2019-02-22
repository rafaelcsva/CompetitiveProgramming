//08, 12, 2018, 08:15:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5;
ll a[N];
ll ques[N];

void solve(int ini, int end){
    for(int k = ini ; k <= end ; k += 4){
        // printf("k = %d\n", k);

        printf("1 %d %d %d\n", k, k + 1, k + 2);
        fflush(stdout);

        scanf("%lld", &ques[k]);
        assert(ques[k] != -1);

        printf("1 %d %d %d\n", k + 1, k + 2, k + 3);
        fflush(stdout);

        scanf("%lld", &ques[k + 1]);
        assert(ques[k + 1] != -1);

        printf("1 %d %d %d\n", k, k + 2, k + 3);
        fflush(stdout);

        scanf("%lld", &ques[k + 2]);
        assert(ques[k + 2] != -1);

        printf("1 %d %d %d\n", k, k + 1, k + 3);
        fflush(stdout);

        scanf("%lld", &ques[k + 3]);
        assert(ques[k + 3] != -1);

        a[k + 2] = (ques[k] ^ ques[k + 1]) ^ ques[k + 2];    
        a[k] = (ques[k + 3] ^ ques[k + 1]) ^ a[k + 2];
        a[k + 3] = (ques[k] ^ ques[k + 1]) ^ a[k];
        a[k + 1] = (ques[k] ^ a[k]) ^ a[k + 2];
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        if(n % 4 == 1){
            printf("1 1 2 3\n");
            fflush(stdout);

            scanf("%lld", &ques[1]);
            assert(ques[1] != -1);

            printf("1 1 4 5\n");
            fflush(stdout);
            
            scanf("%lld", &ques[2]);
            assert(ques[2] != -1);

            printf("1 2 4 5\n");
            fflush(stdout);

            scanf("%lld", &ques[3]);
            assert(ques[3] != -1);

            printf("1 1 3 5\n");
            fflush(stdout);

            scanf("%lld", &ques[4]);
            assert(ques[4] != -1);

            printf("1 2 3 4\n");
            fflush(stdout);
            
            scanf("%lld", &ques[5]);
            assert(ques[5] != -1);

            a[3] = ques[1] ^ (ques[2] ^ ques[3]);
            a[5] = (ques[5] ^ ques[3]) ^ a[3];
            a[1] = (ques[4] ^ a[3]) ^ a[5];
            a[2] = (ques[1] ^ a[1]) ^ a[3];
            a[4] = (ques[2] ^ a[1]) ^ a[5];

            solve(6, n);
        }else if(n % 4 == 2){
            printf("1 1 2 3\n");
            fflush(stdout);

            scanf("%lld", &ques[1]);
            assert(ques[1] != -1);

            printf("1 2 5 6\n");
            fflush(stdout);

            scanf("%lld", &ques[2]);
            assert(ques[2] != -1);

            printf("1 1 5 6\n");
            fflush(stdout);

            scanf("%lld", &ques[3]);
            assert(ques[3] != -1);

            printf("1 3 4 5\n");
            fflush(stdout);
            
            scanf("%lld", &ques[4]);
            assert(ques[4] != -1);

            printf("1 1 2 4\n");
            fflush(stdout);

            scanf("%lld", &ques[5]);
            assert(ques[5] != -1);

            printf("1 3 4 6\n");
            fflush(stdout);

            scanf("%lld", &ques[6]);
            assert(ques[6] != -1);

            a[3] = (ques[2] ^ ques[3]) ^ ques[1];
            a[1] = (ques[6] ^ ques[4]) ^ ques[3];
            a[2] = (ques[1] ^ a[1]) ^ a[3];
            a[4] = (ques[5] ^ a[1]) ^ a[2]; 
            a[5] = ques[4] ^ a[3] ^ a[4];
            a[6] = ques[6] ^ a[3] ^ a[4];

            solve(7, n);
        }else if(n % 4 == 3){
            printf("1 1 2 3\n");
            fflush(stdout);

            scanf("%lld", &ques[1]);
            assert(ques[1] != -1);

            printf("1 1 6 7\n");
            fflush(stdout);

            scanf("%lld", &ques[2]);
            assert(ques[2] != -1);

            printf("1 2 6 7\n");
            fflush(stdout);
            
            scanf("%lld", &ques[3]);
            assert(ques[3] != -1);

            printf("1 3 4 5\n");
            fflush(stdout);

            scanf("%lld", &ques[4]);
            assert(ques[4] != -1);

            printf("1 4 5 6\n");
            fflush(stdout);

            scanf("%lld", &ques[5]);
            assert(ques[5] != -1);

            printf("1 1 2 4\n");
            fflush(stdout);

            scanf("%lld", &ques[6]);
            assert(ques[6] != -1);

            printf("1 3 5 7\n");
            fflush(stdout);

            scanf("%lld", &ques[7]);
            assert(ques[7] != -1);

            a[3] = (ques[2] ^ ques[3]) ^ ques[1];
            a[6] = (ques[4] ^ ques[5]) ^ a[3];
            a[4] = (ques[1] ^ ques[6]) ^ a[3];
            a[7] = (ques[4] ^ ques[7]) ^ a[4];
            a[1] = (ques[2] ^ a[6]) ^ a[7];
            a[2] = (ques[3] ^ a[6]) ^ a[7];
            a[5] = (ques[5] ^ a[4]) ^ a[6];

            solve(8, n);
        }else{
            solve(1, n);
        }  

        printf("2 ");
        fflush(stdout);

        for(int i = 1 ; i <= n ; i++){
            char c = i == n ? '\n' : ' ';
            printf("%lld%c", a[i], c);
            fflush(stdout);
        }
        
        int resp;

        scanf("%d", &resp);

        assert(resp != -1);
    }
    
    return 0;
}