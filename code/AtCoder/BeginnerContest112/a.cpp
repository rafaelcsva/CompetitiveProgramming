//06, 10, 2018, 09:01:24 Rafaelcs cpp
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

    if(n == 1){
        printf("Hello World\n");
    }else{
        int a, b;

        scanf("%d %d", &a, &b);

        printf("%d\n", a + b);
    }
    
    return 0;
}