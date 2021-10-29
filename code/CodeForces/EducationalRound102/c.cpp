#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;

    scanf("%d", &q);

    while(q--){
        int n, k;

        scanf("%d %d", &n, &k);

        vector< int > ans;

        for(int i = 1 ; i <= k ; i++){
            ans.push_back(i);
        }
        int r = n - k + 1;
        // printf("%d\n", r);
        reverse(ans.end() - r , ans.end());

        for(auto u: ans){
            printf("%d ", u);
        }

        printf("\n");
    }

    return 0;
}
