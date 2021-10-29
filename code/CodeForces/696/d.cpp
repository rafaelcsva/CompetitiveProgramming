#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int p[N], s[N];
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        p[n + 1] = s[n + 1] = 0;

        for(int i = 1 ; i <= n ; i++){
            p[i] = a[i];
            s[i] = a[i];
        }

        for(int i = 1 ; i <= n - 1 ; i++){
            int mn = min(p[i], p[i + 1]);

            p[i] -= mn;
            p[i + 1] -= mn;
        }

        for(int i = n ; i >= 2 ; i--){
            int mn = min(s[i], s[i - 1]);

            s[i] -= mn;
            s[i - 1] -= mn;
        }

        for(int i = 1 ; i <= n ; i++){
            
        }
    }

    return 0;
}