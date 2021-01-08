#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll tot = ll(1e10);
char s[N];
string t = "110";

int main(){
    int n;

    scanf("%d", &n);

    scanf("\n%s", s);

    int st = -1;

    for(int j = 0 ; j < 3 ; j++){
        bool ok = true;
        int k = j;

        for(int i = 0 ; i < n ; i++){
            if(t[k] != s[i]){
                ok = false;
                break;
            }

            k = (k + 1) % 3;
        }

        if(ok){
            st = j;
        }
    }

    if(n == 1){
        if(s[0] == '0'){
            printf("%lld\n", tot);
        }else{
            printf("%lld\n", tot * 2LL);
        }

        return 0;
    }

    if(st == -1){
        printf("0\n");
    }else{
        // printf("%lld\n", tot);
        ll ans = 3LL * tot - ll(st) - ll(n);
        ans = (ans) / 3LL;
        ans++;

        printf("%lld\n", ans);
    }

    return 0;
}