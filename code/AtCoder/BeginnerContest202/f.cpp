#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< int, int >    pii;

const int N = 100;
pii p[N];
ll dp1[N][N][N][2][2];
ll dp2[N][N][N][2][2];
const ll mod = ll(1e9) + 7LL;

int cross(pii a, pii b){
    return a.first * b.second - b.first * a.second;
}

bool cck(int i, int j, int k){
    return cross({p[j].first - p[i].first, p[j].second - p[i].second},
        {p[k].first - p[i].first, p[k].second - p[i].second}) > 0;
}

int is_integer(int a, int b, int c){
    if(a == b){
        return 0;
    }
    int sum = p[a].first * p[b].second + p[b].first * p[c].second + p[c].first * p[a].second
        - p[a].first * p[c].second - p[c].first * p[b].second - p[b].first * p[a].second;

    return (sum & 1);
}

ll solve1(int i, int j, int last, int frag = 0, int se = 0){
    ll &ans = dp1[i][j][last][frag][se];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    int av = (frag + is_integer(i, last, j)) & 1;
    if(last != i && av == se){
        ans = 1LL;
    }

    for(int d = last + 1 ; d < j ; d++){
        if((last == i || !cck(i, last, d)) && !cck(last, d, j)){
            ans += solve1(i, j, d, (frag + is_integer(i, last, d)) & 1);
            if(ans >= mod){
                ans -= mod;
            }
        }
    }

    return ans;
}

ll solve2(int i, int j, int last, int frag = 0, int se = 0){
    ll &ans = dp2[i][j][last][frag][se];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    int av = (frag + is_integer(i, last, j)) & 1;

    if(last != i && av == se){
        ans = 1LL;
    }

    for(int d = last + 1 ; d < j ; d++){
        if((last == i || cck(i, last, d)) && cck(last, d, j)){
            ans += solve2(i, j, d, (frag + is_integer(i, last, d)) & 1);
            if(ans >= mod){
                ans -= mod;
            }
        }
    }

    return ans;
}

int main(){
    memset(dp1, -1LL, sizeof dp1);
    memset(dp2, -1LL, sizeof dp2);

    int n;
    
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    sort(p, p + n);

    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 2 ; j < n ; j++){
            auto lf = solve1(i, j, i);      
            auto rg = solve2(i, j, i);

            ans += (lf + 1LL) * rg;
            ans %= mod;
            ans += lf * (rg + 1LL);
            ans %= mod;

            auto lf1 = solve1(i, j, 0, 1);
            auto rg1 = solve2(i, j, 0, 1);

            ans += lf1 * rg1;
            ans %= mod;
        }
    }

    printf("%lld\n", ans);

    return 0;
}