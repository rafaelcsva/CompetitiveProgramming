//14, 11, 2018, 13:36:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int a[1010];
int n;

bool can_erase(int i, int j){
    if(i == 0 && j == n - 1){
        return false;
    }

    if(i == 0){
        int lf = a[j + 1] - 1;

        for(int k = j ; k >= i ; k--){
            if(a[k] != lf){
                return false;
            }

            lf--;
        }

        if(lf != 0){
            return false;
        }
    }else if(j == n - 1){
        int rg = a[i - 1] + 1;

        for(int k = i ; k <= j ; k++){
            if(a[k] != rg){
                return false;
            }

            rg++;
        }

        if(rg != 1000 + 1){
            return false;
        }
    }else{
        int rg = a[i - 1] + 1;

        for(int k = i ; k <= j ; k++){
            if(a[k] != rg){
                return false;
            }

            rg++;
        }

        if(a[j + 1] != rg){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    int best = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            if(can_erase(i, j)){
                // printf("%d, %d\n", i, j);
                best = max(best, j - i + 1);
            }
        }        
    }

    printf("%d\n", best);

    return 0;
}