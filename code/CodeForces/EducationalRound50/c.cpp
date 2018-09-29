//07, 09, 2018, 12:34:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int D = 21;
int digts_r[D], digts_l[D];
ll dp[D][3][3][5];
int used[D][3][3][5];
int test;
int M = 3LL;

ll solve(int digt, bool is_less, bool is_greater, int nzero_nums){
    if(nzero_nums > M){
        return 0LL;
    }
    if(digt == 0){
        return 1;
    }

    int &us = used[digt][is_less][is_greater][nzero_nums];
    ll &ans = dp[digt][is_less][is_greater][nzero_nums];
    
    if(us == test){
        return ans;
    }

    us = test;
    ans = 0LL;

    if(is_less && is_greater){
        for(int d = 0 ; d <= 9 ; d++){
            ans += solve(digt - 1, is_less, is_greater, nzero_nums + (d != 0));
        }
    }else if(is_less){
        for(int d = digts_l[digt] ; d <= 9 ; d++){
            ans += solve(digt - 1, is_less, d != digts_l[digt], nzero_nums + (d != 0));
        }
    }else if(is_greater){
        for(int d = 0 ; d <= digts_r[digt] ; d++){
            ans += solve(digt - 1, d != digts_r[digt], is_greater, nzero_nums + (d != 0));
        }
    }else{
        for(int d = digts_l[digt] ; d <= digts_r[digt] ; d++){
            ans += solve(digt - 1, d != digts_r[digt], d != digts_l[digt], nzero_nums + (d != 0));
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        ll l, r;

        scanf("%lld %lld", &l, &r);

        int d = 1;

        while(l){
            digts_l[d] = l % 10LL;
            l /= 10LL;
            d++;
        }

        d = 1;

        while(r){
            digts_r[d] = r % 10LL;
            r /= 10LL;
            d++;
        }

        printf("%lld\n", solve(D - 1, false, false, 0));

        memset(digts_l, 0, sizeof digts_l);
        memset(digts_r, 0, sizeof digts_r);
    }

    return 0;
}