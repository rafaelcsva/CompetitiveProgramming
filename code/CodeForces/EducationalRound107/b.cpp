#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 13;
vector< ll > d2, d3;

int cnt_digit(ll d){
    int cnt = 0;
    while(d){
        d /= 10LL;
        // printf("%lld\n", d);
        cnt++;
    }

    return cnt;
}

int main(){
    ll st = 2LL;
    while(d2.size() != N){
        int d = cnt_digit(st);

        if(d == int(d2.size()) + 1LL){
            d2.push_back(st);
            // printf("%lld\n", st);
        } 

        // printf("%lu %d %lld\n", d2.size(), d, st);

        st <<= 1LL;
        // break;
    }

    st = 3LL;
    while(d3.size() != N){
        int d = cnt_digit(st);

        if(d == int(d3.size()) + 1LL){
            d3.push_back(st);
        }

        st = st * 3LL;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        ll pt = 1LL;
        int tc = c;
        c--;
        while(c){
            pt = pt * 10LL;
            c--;
        }

        printf("%lld %lld\n", d2[a - tc] * pt, d3[b - tc] * pt);
        // printf("%lld\n", __gcd(d2[a - c] * pt, d3[b - c] * pt));
    }
    
    return 0;
}