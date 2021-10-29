#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        vector< int > v;

        scanf("%d", &n);

        for(int i = 0 ; i < 2 * n ; i++){
            int ai;

            scanf("%d", &ai);
            v.push_back(ai);
        }

        sort(v.begin(), v.end());
        vector< int > ve;

        for(int i = 0, j = int(v.size()) - 1 ; i <= j ; i++, j--){
            ve.push_back(v[i]);
            ve.push_back(v[j]);
        }

        for(auto u: ve){
            printf("%d ", u);
        }
        printf("\n");
    }
}