#include <bits/stdc++.h>

using namespace std;

const int N = 810;

int prefl[N][N];
int prefc[N][N];
int sum[N][N];
int a[N][N];
int ta[N][N];
int n, k;

bool can(int mid){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            ta[i][j] = (a[i][j] <= mid);
            prefl[i][j] = prefl[i - 1][j] + ta[i][j];
            prefc[i][j] = prefc[i][j - 1] + ta[i][j];
            sum[i][j] = sum[i - 1][j - 1] + prefc[i][j - 1] + prefl[i][j];
        }
    }

    for(int i = k ; i <= n ; i++){
        for(int j = k ; j <= n ; j++){
            int msum = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];

            if(msum >= (k * k + 1) / 2){
                return true;
            }
        }
    }

    return false;
}

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    int lo = 0, hi = int(1e9);
    int r = -1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        // printf("%d\n", mid);
        if(can(mid)){
            r = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    assert(r != -1);
    printf("%d\n", r);

    return 0;
}