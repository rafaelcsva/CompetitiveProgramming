//06, 10, 2018, 09:03:03 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t;

    scanf("%d %d", &n, &t);

    int r = -1;

    for(int i = 0 ; i < n ; i++){
        int c, x;

        scanf("%d %d", &c, &x);

        if(t >= x){
            if(r == -1){
                r = c;
            }else{
                r = min(r, c);
            }
        }
    }

    if(r == -1){
        printf("TLE\n");
    }else{
        printf("%d\n", r);
    }
    
    return 0;
}