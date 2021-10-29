#include <bits/stdc++.h>

using namespace std;

const int N = int(4e5) + 10;
int x[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < k ; i++){
            scanf("%d", &x[i]);
        }

        sort(x, x + k);

        int qtd = 0;
        int save = 0;

        for(int d = k - 1 ; d >= 0 ; d--){
            if(qtd < x[d]){
                save++;
            }else{
                break;
            }

            qtd += n - x[d];
        }

        printf("%d\n", save);
    }

    return 0;
}