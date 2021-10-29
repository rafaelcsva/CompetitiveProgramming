#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, r, c;

        scanf("%d %d %d %d", &n, &m, &r, &c);

        int ans = max(n - r, r - 1) + max(m - c, c - 1);

        printf("%d\n", ans);
    }

    return 0;
}