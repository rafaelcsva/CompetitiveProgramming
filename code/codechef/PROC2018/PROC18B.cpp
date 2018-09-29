//16, 08, 2018, 12:38:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5);
ld a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%Lf", &a[i]);
        }

        sort(a, a + n);

        ld have = a[n - 1];

        for(int i = n - 2 ; i >= 0 ; i--){
            have = (a[i] + have) / 2.0L;
        }

        printf("%.7Lf\n", have);
    }   

    return 0;
}