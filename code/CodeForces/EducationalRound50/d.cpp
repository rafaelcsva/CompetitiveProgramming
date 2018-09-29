//07, 09, 2018, 12:55:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const int N = int(3e5 + 100);
map< ll, bool > mp;
ll a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);

        a[i] += a[i - 1];
    }

    int m;

    scanf("%d", &m);

    for(int i = 1 ; i <= m ; i++){
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];

        mp[b[i]] = true;
    }

    if(a[n] != b[m]){
        printf("-1\n");
    }else{
        int cnt = 0;
        
        for(int i = 1 ; i <= n ; i++){
            if(mp[a[i]]){
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }
    
    return 0;
}