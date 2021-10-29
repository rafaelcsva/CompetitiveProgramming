#include <bits/stdc++.h>

using namespace std;

const int N = 510;
bitset< N > ans[N];
int where[N];

bool gauss(vector< pair< int, bitset< N > > > a, int n, int m){
    for(int col = 0, row = 0; col < m && row < n ; ++col){
        for(int i = row ; i < n ; i++){
            if(a[i].second[col]){
                swap(a[i], a[row]);
                break;
            }
        }

        if(!a[row].second[col]){
            return false;
        }

        where[col] = a[row].first;

        for(int i = 0 ; i < n ; ++i){
            if(i != row && a[i].second[col]){
                ans[a[i].first] ^= ans[a[row].first];
                a[i].second ^= a[row].second;
            }
        }

        ++row;
    }

    return true;
}

int main(){
    int n;

    scanf("%d", &n);

    vector< pair< int, bitset< N > > > ques;

    for(int i = 1 ; i <= n ; i++){
        bitset< N > bst;

        for(int j = 0 ; j < n ; j++){
            int xj;

            scanf("%d", &xj);

            bst[j] = xj;
        }

        ques.push_back({i, bst});
        ans[i][i] = 1;
    }

    if(gauss(ques, n, n)){
        for(int i = 0 ; i < n ; i++){
            for(int d = 0 ; d < N ; d++){
                if(ans[where[i]][d]){
                    printf("%d ", d);
                }
            }
            printf("\n");
        }
    }else{
        printf("-1\n");
    }

    return 0;
}