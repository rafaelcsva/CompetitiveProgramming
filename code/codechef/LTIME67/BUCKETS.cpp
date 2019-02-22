//29, 12, 2018, 12:08:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010, K = 1010, D = 20;
double p[N][K][D];
int a[N][K];
int tot[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            scanf("%d", &a[i][j]);
            
            if(i == 1){
                p[i][j][a[i][j]] = 1.0;
            }

            tot[i] += a[i][j];
        }
       // printf("%d: %d\n", i, tot[i]);
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            p[i][j][a[i][j] + 1] = p[i - 1][j][a[i - 1][j]] * (double(a[i - 1][j]) / double(tot[i - 1]));
            p[i][j][a[i][j] + 1] += p[i - 1][j][a[i - 1][j] + 1] * (double(a[i - 1][j] + 1) / double(tot[i - 1]));

            p[i][j][a[i][j]] = 1.0 - (p[i - 1][j][a[i - 1][j]] * (double(a[i - 1][j]) / double(tot[i - 1]))
                            + p[i - 1][j][a[i - 1][j] + 1] * (double(a[i - 1][j] + 1) / double(tot[i - 1])));      
        }

        tot[i]++;
    }

    for(int j = 1 ; j <= k ; j++){
        double prob = p[n][j][a[n][j]] * (double(a[n][j]) / double(tot[n]));
        prob += p[n][j][a[n][j] + 1] * (double(a[n][j] + 1) / double(tot[n]));
        char c = (j == k) ? '\n' : ' ';

        printf("%.7lf%c", prob, c);
    }

    return 0;
}