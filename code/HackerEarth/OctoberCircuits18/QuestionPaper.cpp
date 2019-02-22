//26, 10, 2018, 21:55:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e6 + 10;
const int DESLOC = 1e6;
int mark[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n, a, b;

        scanf("%d %d %d", &n, &a, &b);

        int cnt = 0;

        for(int i = 0 ; i <= n ; i++){
            int mx = (n - i) * b;
            int aa = i * a;
            int err = 0;

            // printf("%d %d\n", aa, mx);
            while(err <= mx){
                if(mark[aa - err + DESLOC]){
                    break;
                }
                //  printf("entrei! (%d) %d\n", mark[4], aa - err);
                
                mark[aa - err + DESLOC] = true;
                
                err += b;
                // printf("%d + %d = %d (%d)\n", init, aa, init + aa, mark[init + aa]);
                cnt++;
            }
            // printf("exited!\n");
        }  
        // printf("%d\n", cnt);

        printf("%d\n", cnt);

        memset(mark, 0, sizeof mark);
    }
    
    return 0;
}