#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
multiset< ll > mst;
ll a[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
    }

    int ans = 0;
    ll life = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(a[i] >= 0LL){
            ans++;
            life += a[i];
        }else{
            if(life + a[i] < 0LL){
                // printf("qui %d\n", i + 1);
                if(mst.size() > 0){
                    // printf("sub")
                    ll lss = *mst.begin();

                    if(lss < a[i]){
                        life -= lss;
                        life += a[i];
                        mst.erase(mst.begin());
                        mst.insert(a[i]);
                    }
                }
            }else{
                life += a[i];
                ans++;
                mst.insert(a[i]);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}