//19, 10, 2018, 16:38:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
int a[N];

bool is_sort(int n){
    for(int i = 1 ; i < n ; i++){
        if(a[i - 1] > a[i] ){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int mx = -1;

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            mx = max(a[i], mx);
        }

        if(is_sort(n)){
            printf("YES\n");
            continue;
        }

        int k = 0;
        bool ok = true;

        if(a[n - 1] != mx){

            for(k = n - 1 ; k >= 0 ; k--){
                if(a[k] == mx){
                    break;
                }
            }

        }else{
            bool ver = false;

            for(k = n - 1 ; k >= 0 ; k--){
                if(a[k] != mx){
                    ver = true;
                }else{
                    if(ver){
                        break;
                    }
                }
            }

            k = max(k, 0);
        }

        int j;

        for(j = 1, k = (k + 2) % n ; j < n ; k = (k + 1) % n, j++){
            int past = (k - 1 + n) % n;
            
            if(a[past] > a[k]){ 
                ok = false;
                break;
            }
        }

        if(!ok){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}