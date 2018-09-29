//08, 08, 2018, 11:27:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    int l = 1, r = 2;

    while(l <= n && r <= n){
        printf("%d %d ", r, l);
        r += 2;
        l += 2;
    }

    if(n & 1){
        printf("%d", l);
    }
    
    printf("\n");

    return 0;
}