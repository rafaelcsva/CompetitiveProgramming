#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int dp_left[N];
int dp_right[N];
int a[N];
int con[N];

bool test(int i, int j){
    if(a[i] == -1 || a[j] == -1){
        return true;
    }

    return a[i] <= a[j];
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = n + 1 ; i <= 2 * n ; i++){
        a[i] = -1;
    }

    int m = n;

    n *= 2;

    for(int i = 1 ; i <= n ; i++){
        con[i] = int(1e9);
    }

    int last_one = 0;
    dp_left[0] = dp_right[n + 1] = -1;

    for(int i = 1 ; i <= n ; i++){
        if(a[last_one] <= a[i] || a[i] == -1){
            dp_left[i] = dp_left[last_one] + (i - last_one);
        }else{
            dp_left[i] = (i - last_one - 1);
        }

        if(a[i] != -1){
            last_one = i;
        }
    }

    last_one = n + 1;

    for(int i = n ; i >= 1 ; i--){
        if(a[last_one] <= a[i] || a[i] == -1){
            dp_right[i] = dp_right[last_one] + (last_one - i);
        }else{
            dp_right[i] = (last_one - i - 1);
        }

        if(a[i] != -1){
            last_one = i;
        }
    }

    // for(int i = 1 ; i <= n ; i++){
    //     printf("%d |%d, %d|\n", i, dp_left[i], dp_right[i]);
    // }

    for(int i = 1 ; i <= n ; i++){
        con[i + dp_right[i]] = min(con[i + dp_right[i]], i - dp_left[i]);
    }

    for(int i = n - 1 ; i >= 1 ; i--){
        con[i] = min(con[i], con[i + 1]);
    }

    for(int i = 3 ; i <= n ; i++){
        if(m % i && m % i < 3){
            continue;
        }

        for(int j = i ; j <= n ; j += i){
            int l = j - i + 1;
            int r = min(j, m);

            if(!(con[r] <= l && test(r, r - 1) && test(l, l + 1))){
                break;
            }

            if(r == m){
                printf("Y\n");
                return 0;
            }
        }
    }

    printf("N\n");

    return 0;
}