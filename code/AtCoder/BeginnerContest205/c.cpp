#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll a, b, c;

    scanf("%lld %lld %lld", &a, &b, &c);

    if((c & 1LL) == 0LL){
        a = abs(a);
        b = abs(b);
    }

    if(a > b){
        printf(">\n");
    }else if(a < b){
        printf("<\n");
    }else{
        printf("=\n");
    }

    return 0;
}