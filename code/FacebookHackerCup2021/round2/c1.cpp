#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > tab;

int sum(int i, int l, int r){
    if(l > r){
        swap(l, r);
    }

    if(l < 1){
        l = 1;
    }

    int n = tab.size() - 1;

    if(r > n){
        r = n;
    }
    
    return tab[r][i] - tab[l - 1][i];
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int r, c, k;

        scanf("%d %d %d", &r, &c, &k);

        tab.resize(r + 1);
        tab[0].resize(c, 0);

        for(int i = 1 ; i <= r ; i++){
            for(int j = 0 ; j < c ; j++){
                char c;

                scanf("\n%c", &c);

                tab[i].push_back(c == 'X' ? 1 : 0);
                // printf("%lu %lu %d\n", tab[i].size(), tab.size(), i);
                tab[i][j] += tab[i - 1][j];
            }
        }

        int ans = int(1e9) + 10;

        for(int l = 0 ; l <= r ; l++){
            int tans1 = 0;

            for(int j = 0 ; j < c ; j++){
                if(k - l >= 1 && sum(j, k - l, k - l)){
                    tans1++;
                }else if(sum(j, k - l, r) >= r - k + 1){
                    tans1++;
                }
            }

            int tans2 = 0;

            for(int j = 0 ; j < c ; j++){
                if(k + l <= r && sum(j, k + l, k + l)){
                    tans2++;
                }else if(sum(j, 1, k + l) >= k){
                    tans2++;
                }
            }

            // if(l == 0){
            //     printf("%d, %d\n", tans1, tans2);
            // }
            ans = min(ans, l + min(tans1, tans2));
        }

        printf("Case #%d: %d\n", test, ans);

        for(int i = 0 ; i <= r ; i++){
            for(int j = 0 ; j < c ; j++){
                tab[i][j] = 0;
            }
            tab[i].clear();
        }
    }

    return 0;
}