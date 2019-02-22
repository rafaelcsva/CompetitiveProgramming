//01, 11, 2018, 18:38:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int T = 2010, F = 510;
int t, h, f;
int acorn[T][T];
int best[T];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;

    scanf("%d", &c);

    while(c--){
        scanf("%d %d %d", &t, &h, &f);

        for(int i = 0 ; i < t ; i++){
            int sz;

            scanf("%d", &sz);

            for(int j = 0 ; j < sz ; j++){
                int hi;

                scanf("%d", &hi);

                acorn[i][hi]++;
            }
        }

        for(int i = 0 ; i < t ; i++){
            best[h] = max(acorn[i][h], best[h]);
        }

        for(int i = h - 1 ; i >= 0 ; i--){
            for(int k = 0 ; k < t ; k++){
                acorn[k][i] += max(acorn[k][i + 1], (i + f) <= h ? best[i + f] : 0);
                best[i] = max(best[i], acorn[k][i]);
            }
        }

        printf("%d\n", best[0]);

        memset(best, 0, sizeof best);
        memset(acorn, 0, sizeof acorn);
    }

    return 0;
}