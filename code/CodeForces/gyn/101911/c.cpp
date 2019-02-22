//30, 11, 2018, 16:06:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
int a[N];
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    scanf("%d", &n);

    int g = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        g = __gcd(a[i], g);
    }

    for(int i = 0 ; i < n ; i++){
        a[i] /= g;

        if(__builtin_popcount(a[i]) != 1){
            printf("-1\n");
            return 0;
        }

        int e = 0;
        int cur = 1;

        while(cur < a[i]){
            cur *= 2;
            e++;
        }

        cnt[e]++;
    }

    int insert = 0;

    for(int i = 0 ; i < N ; i++){
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] = cnt[i] & 1;

        if(cnt[i] == 1){
            bool find = false;

            for(int j = i + 1 ; j < N ; j++){
                if(cnt[j]){
                    find = true;
                    break;
                }
            }

            if(find){
                insert++;
                cnt[i + 1]++;
            }else{
                break;
            }
        }
    }

    printf("%d\n", insert);

    return 0;
}