#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int l[N];

int main(){
    int t;
    int test = 1;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &l[i]);
        }

        int cost = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            int pos = i;
            for(int j = i ; j < n ; j++){
                if(l[j] < l[pos]){
                    pos = j;
                }
            }

            cost += pos - i + 1;

            reverse(l + i, l + pos + 1);
        }

        printf("Case #%d: %d\n", test++, cost);
    }

    return 0;
}