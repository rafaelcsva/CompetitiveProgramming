//05, 09, 2018, 13:37:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 30;
int c[3];
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d %d %d", &n, &c[0], &c[1]);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    int total = 0;

    for(int i = 0, j = n - 1 ; i < n / 2 ; i++, j--){
        if(a[i] == 2){
            if(a[j] != 2){
                total += c[a[j]];
            }else{
                total += 2 * min(c[0], c[1]);
            }
        }else if(a[j] == 2){
            if(a[i] != 2){
                total += c[a[i]];
            }else{
                total += 2 * min(c[0], c[1]);
            }
        }else{
            if(a[i] != a[j]){
                printf("-1\n");
                return 0;
            }
        }
    }

    if(n & 1){
        if(a[n / 2] == 2){
            total += min(c[0], c[1]);
        }
    }

    printf("%d\n", total);

    return 0;
}