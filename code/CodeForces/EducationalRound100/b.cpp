#include <bits/stdc++.h>

using namespace std;

const int N = 60;
int a[N];
int mn = int(1e9) + 10;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            mn = min(mn, a[i]);
        }

        for(int i = 0 ; i < n ; i++){
            
        }
    }

    return 0;
}