//20, 10, 2018, 18:27:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
int a[N];
int n;

bool can(int k, int fi){
    if(a[fi] > k){
        return false;
    }

    int st = a[fi];

    for(int i = fi ; i < n ; i++){
        if(a[i] != -1 && a[i] != st){
            return false;
        }

        st = st % k + 1;
        // printf("%d %d\n", st, k);
    }
    // printf("posso com %d %d\n", k, fi);
    return true;
}

int get_best(bool &ok, int r, int l, int fi){
    if(l > r){
        ok = false;
        return 0;
    }

    int len = (r - l) + 1;
    // printf("len = %d\n", len);
    int best = -1;

    for(int i = 1 ; i * i <= len ; i++){
        if(len % i == 0){
            if(can(i, fi)){
                best = max(best, i);
            }

            if(can(len / i, fi)){
                best = max(best, len / i);
            }
        }
    }
    
    if(best == -1){
        ok = false;
    }

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        int k = 0;

        for(k = 0 ; k < n ; k++){
            if(a[k] != -1){
                break;
            }
        }

        int fi = k;

        if(k >= n){
            printf("inf\n");
        }else{
            int st = a[k];
            int bf = -1;
            bool ok = true;

            for(int i = k ; i < n ; i++){
                if(a[i] != st && a[i] != -1){
                    if(i - a[i] < 0){
                        ok = false;
                        break;
                    }
                    // printf("aqui! %d %d\n", i,  (fi - a[fi] + 1));

                    bf = get_best(ok, (i - a[i]), (fi - a[fi] + 1), fi);
                    break;
                }

                st++;
            }

            if(!ok){
                printf("impossible\n");
            }else{
                if(bf == -1){
                    printf("inf\n");
                }else{
                    printf("%d\n", bf);
                }
            }
        }
    }

    return 0;
}