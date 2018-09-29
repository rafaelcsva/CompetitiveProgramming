//18, 08, 2018, 12:08:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll inf = 1e9;
const int N = int(1e6 + 10);
int mark[N];
vector< ll > sticks;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            ll l;

            scanf("%lld", &l);

            if(mark[l] == test){
                sticks.push_back(l);
                mark[l] = 0;
            }else{
                mark[l] = test;
            }
        }

        sort(sticks.begin(), sticks.end());

        ll num = inf, dem = 1LL;
        ll resp1 = -1, resp2 = -1;

        for(int i = 1 ; i < sticks.size() ; i++){
            ll area = sticks[i] * sticks[i - 1];
            ll per = sticks[i] + sticks[i - 1];

            per *= per;

            if(num * area > dem * per){
                resp1 = sticks[i];
                resp2 = sticks[i - 1];
                num = per;
                dem = area;
            }
        }

        printf("%lld %lld %lld %lld\n", resp1, resp1, resp2, resp2);

        sticks.clear();
    }
        
    return 0;
}