#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];
int cnt[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        
        for(int i = 0 ; i <= 100 ; i++){
            if(cnt[i]){
                printf("%d ", i);
                cnt[i]--;
            }else{
                break;
            }
        }

        for(int i = 0 ;i <= 100 ; i++){
            while(cnt[i]){
                printf("%d ", i);
                cnt[i]--;
            }
        }

        printf("\n");
    }

    return 0;
}