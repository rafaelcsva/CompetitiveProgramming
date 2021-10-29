#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int D = 11;
ll dp[D][D][2];
int test[D][D][2];
int testnum = 1;

ll solve(int i, int j, int frag, vector< int > &num){
    if(i <= j){
        return frag;
    }

    auto &tst = test[i][j][frag];
    ll &ans = dp[i][j][frag];
    if(tst == testnum){
        return ans;
    }

    ans = 0LL;
    tst = testnum;

    for(int e = 0 ; e < 10 ; e++){
        if(!frag && e > num[i - 1]) break;
        // printf("%d %d\n", e, num[i - 1]);

        ans += solve(i - 1, j, frag || (e < num[i - 1]), num);
    }

    return ans;
}

vector< int > get_num(int x){
    vector< int > num;

    while(x){
        num.push_back(x % 10);
        x /= 10;
    }

    return num;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int l, r;

        scanf("%d %d", &l, &r);
        ll ans = 0LL;

        auto vl = get_num(l);
        auto vr = get_num(r);

        for(int i = 0 ; i < D ; i++){
            ans += solve(vr.size(), i, 0, vr);
            // printf("add %lld\n", solve(vr.size(), i, 0, vr));
            testnum++;

            ans -= solve(vl.size(), i, 0, vl);
            // printf("rem %lld\n", solve(vl.size(), i, 0, vl));
            testnum++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}