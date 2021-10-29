#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

typedef pair< ll, ll >  pll;

const int N = int(1e5) + 10;
pll p[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &p[i].second, &p[i].first);
    }

    sort(p, p + n);

    int i = 0;
    int j = n - 1;
    ll cost = 0LL;
    ll cur = 0LL;

    while(i <= j){
        while(i <= j && cur >= p[i].first){
            cost += p[i].second;
            cur += p[i].second;
            // printf("1 buy %lld from %d\n", p[i].second, i + 1);
            i++;
        }

        if(j >= i){
            ll need = p[i].first - cur;

            if(need >= p[j].second){
                cost += p[j].second * 2LL;
                cur += p[j].second;
                j--;
            }else{
                cost += need * 2LL;
                cur += need;
                p[j].second -= need; 
            }
        }
    }

    printf("%lld\n", cost);

    return 0;
}