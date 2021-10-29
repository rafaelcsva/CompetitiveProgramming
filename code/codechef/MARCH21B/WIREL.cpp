#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
int x[N], y[N], a[N], b[N], c[N], d[N];

int main(){
    srand(time(NULL));
    int n, m;
    
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    for(int i = 0 ; i < m ; i++){
        printf("%d %d\n", rand() % 100, rand() % 100);
    }

    return 0;
}