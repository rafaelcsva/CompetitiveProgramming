#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5);
int a[N];

int main(){
    int q;

    scanf("%d", &q);

    while(q--){
        int n, d;

        scanf("%d %d", &n, &d);

        for(int i = 0 ; i < n ; i++) scanf("%d", &a[i]);
        sort(a, a + n);

        if(a[n - 1] > d && a[0] + a[1] > d){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}