#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < n / 2 ; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a + n / 2);

    int j = 0;
    int ans = int(1e9);

    int tmp1 = 0;

    for(int d = 1 ; j < n / 2 ; d += 2, j++){
        tmp1 += abs(a[j] - d);
    }

    int tmp2 = 0;
    j = 0;
    for(int d = 2 ; j < n / 2 ; d += 2, j++){
        tmp2 += abs(a[j] - d);
    }

    int tmp3 = 0;
    j = n / 2 - 1;
    for(int d = n ; j >= 0 ; d -= 2, j--){
        tmp3 += abs(a[j] - d);
    }

    int tmp4 = 0;
    j = n / 2 - 1;

    for(int d = n - 1 ; j >= 0 ; d -= 2, j--){
        tmp4 += abs(a[j] - d);
    }

    ans = min({tmp1, tmp2, tmp3, tmp4});

    printf("%d\n", ans);

    return 0;
}