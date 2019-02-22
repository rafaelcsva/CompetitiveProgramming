//06, 10, 2018, 09:42:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    scanf("%d %d", &n, &m);

    int r = -1;

    for(int i = 1 ; i * i <= m ; i++){
        if(m % i == 0){
            int a = m / i;
            
            if(m / a >= n){
                r = max(r, a);
            }

            if(m / i >= n){
                r = max(r, i);
            }
        }
    }

    printf("%d\n", r);

    return 0;
}