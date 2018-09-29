//05, 09, 2018, 13:51:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);

    int best = 1e9, ind = -1;

    for(int i = 1 ; i <= min(n, k + 1) ; i++){
        int tmp = 1;

        for(int j = i + k + 1 ; j <= n ; j += 2 * k + 1){
            tmp++;
            int next = j + 2 * k + 1;
            int r = n - j + 1;

            if(r < k + 1){
                // printf("%d %d\n", i, j);
                tmp = 1e9;
            }
        }

        if(best > tmp){
            best = tmp;
            ind = i;
        }
    }

    printf("%d\n", best);

    for(int i = ind ; i <= n ; i += 2 * k + 1){
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}