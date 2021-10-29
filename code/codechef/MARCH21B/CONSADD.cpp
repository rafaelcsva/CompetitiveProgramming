#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 1010;
ll a[N][N];
ll b[N][N];
ll mc[N][N];
ll coefrow[N][N];
ll coefcol[N][N];
ll sumh[N][N], sumv[N][N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int r, c, x;

        scanf("%d %d %d", &r, &c, &x);

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                scanf("%lld", &a[i][j]);
            }
        }

        ll sum = 0LL;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                scanf("%lld", &b[i][j]);
                mc[i][j] = b[i][j] - a[i][j];
            }
        }

        bool ok = true;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                ll prev = 0LL;
                ll preh = 0LL;

                if(i){
                    prev += sumv[i - 1][j];

                    if(i >= x){
                        prev -= coefcol[i - x][j];
                    }
                }

                if(j){
                    preh += sumh[i][j - 1];

                    if(j >= x){
                        preh -= coefrow[i][j - x];
                    }
                }

                ll sv = mc[i][j] - (prev + preh);

                if(sv){
                    if(i + x <= r){
                        coefcol[i][j] = sv;
                        coefrow[i][j] = 0LL;
                        prev += sv;
                    }else if(j + x <= c){
                        coefrow[i][j] = sv;
                        coefcol[i][j] = 0LL;
                        preh += sv;
                    }else{
                        ok = false;
                    }
                }else{
                    coefcol[i][j] = coefrow[i][j] = 0LL;
                }

                sumv[i][j] += prev;
                sumh[i][j] += preh;
            }
        }

        if(ok){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
