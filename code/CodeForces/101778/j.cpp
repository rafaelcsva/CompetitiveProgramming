#include <bits/stdc++.h>

using namespace std;
 
typedef long long   ll;
 
bool found(ll &x){
    // printf("%lld\n", x);
    int d = 0;
 
    ll tmp = x;
    while(tmp){
        d++;
        tmp /= 10LL;
    }
 
    if(d == 1){
        return false;
    }
 
    d /= 2;
    int dd = d;
 
    ll n1 = 0LL;
    ll p = 1LL;
 
    tmp = x;
    int pnt = 0;
    int rec = 0;
    ll prec = 0LL;
 
    while(d){
        if(tmp % 10LL){
            rec = pnt + 1;      
        }
 
        n1 = p * (tmp % 10LL) + n1;
        p = (p * 10LL);
 
        d--;
        tmp /= 10LL;
        pnt++;
    }
 
    if(n1 == 0){
        return false;
    }
 
    if(rec != dd){
        // printf("%d %d\n", rec, dd);
        x -= n1;
 
        return false;
    }
    // printf("%lld %lld\n", n1, x);
    return __gcd(n1, tmp) == 1LL;
}

int main(){
    int t;
 
    scanf("%d", &t);
 
    while(t--){
        ll l, r;
        scanf("%lld %lld", &l, &r);
 
        while(!found(r) && l <= r){
            r--;
        }
 
        if(r < l){
            printf("-1\n");
            continue;
        }
 
        printf("%lld\n", r);
    }
 
    return 0;
}