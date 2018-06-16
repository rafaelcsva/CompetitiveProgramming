//24, 05, 2018, 19:40:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 1100;
int v[N];

int main(){
    int n;
    
    while(scanf("%d", &n) && n){
        int tot = 0;

        for(int i = 0 ; i < n ; i++){
            int l, r;

            scanf("%d.%d", &l, &r);

            v[i] = l * 100 + r;
            tot += v[i];
        }

        sort(v, v + n);

        int remainder = tot % n;
        tot /= n;

        int sum = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(v[i] <= tot){
                sum += tot - v[i];
            }else{
                remainder = max(0, remainder - 1);
            }
        }

        sum += remainder;
        
        printf("$%d.%02d\n", sum / 100, sum % 100);
    }

    return 0;
}