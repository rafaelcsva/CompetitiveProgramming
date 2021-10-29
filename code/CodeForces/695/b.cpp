#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;
int tp[N];
int a[N];

bool valid(int a, int b, int c){
    if(a == -1 || c == -1) return false;

    return (a < b && b > c) || (a > b && b < c);
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            tp[i] = 0;
        }
        a[n] = -1;
        int cnt = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                tp[i] = 1;
            }
            if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                tp[i] = 2;
            }
            cnt += (tp[i] != 0);
        }
        if(cnt <= 1){
            printf("0\n");
            continue;
        }
        int ret = 0;
        bool frag = false;
        for(int i = 1 ; i < n - 1 ; i++){
            int tmp = 0;
            int vi1 = 0;
            int vi2 = 0;

            if(valid(i >= 2 ? a[i - 2] : -1, a[i - 1], a[i + 1])){
                vi1 = 1; 
            }
            if(tp[i]){
                tmp++;
            }
            if(tp[i + 1]){
                tmp++;
            }
            if(!vi1 && tp[i - 1]){
                tmp++;
            }
            if(vi1 && !tp[i - 1]){
                tmp--;
            }
            ret = max(ret, tmp);

            vi1 = 0, vi2 = 0, tmp = 0;

            if(valid(a[i - 1], a[i + 1], a[i + 2])){
                vi2 = 1;
            }

            if(tp[i]){
                tmp++;
            }
            if(tp[i - 1]){
                tmp++;
            }
            if(!vi2 && tp[i + 1]){
                tmp++;
            }
            if(vi2 && !tp[i + 1]){
                tmp--;
            }
            // if(ret == 2){
            //     printf("on %d (%d, %d) (%d, %d, %d)\n", i, tp[i], vi2, a[i - 1], a[i + 1], a[i + 2]);
            // }
            ret = max(ret, tmp);
        }

        assert(cnt >= ret);
        // printf("%d, %d\n", cnt, ret);
        printf("%d\n", cnt - ret);
    }

    return 0;
}