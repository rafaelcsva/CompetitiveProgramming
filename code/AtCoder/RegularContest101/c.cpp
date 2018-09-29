//25, 08, 2018, 09:03:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5);
int x[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &x[i]);
    }

    int best = 1e9;
    
    for(int j = 0 ; j <= n - k ; j++){
        int rg = x[j + k - 1];

        if(x[j] < 0){
            if(rg <= 0){
                best = min(best, abs(x[j]));
            }else{
                best = min(best, min(abs(x[j]) * 2 + rg, rg * 2 + abs(x[j])));
            }
        }else{
            best = min(best, x[j + k - 1]);
        }
    }

    printf("%d\n", best);

    return 0;
}