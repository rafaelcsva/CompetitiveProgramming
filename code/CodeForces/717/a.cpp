#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

        for(int i = 0 ; i < n - 1 ; i++){
            while(a[i] && k){
                a[i]--;
                a[n - 1]++;
                k--;
            }
        }

        for(int i = 0 ; i < n ; i++){
            printf("%d ", a[i]);
        }

        printf("\n");
    }
}