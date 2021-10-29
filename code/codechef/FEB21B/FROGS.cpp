#include <bits/stdc++.h>

using namespace std;

const int N = 5;
int w[N];
int l[N];
int ind[N];

bool compar(int i, int j){
    return w[i] < w[j];
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1; test <= t ; test++){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &w[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &l[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            ind[i] = i;
        }

        sort(ind + 1, ind + n + 1, compar);

        int st = 0;
        int ans = 0;

        for(int i = 1 ; i <= n ; i++){
            if(ind[i] > st){
                st = ind[i];
                continue;
            }else{
                int r = st - ind[i];
                int k = (r / l[ind[i]]) + 1;

                ans += k;
                st = ind[i] + k * l[ind[i]];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}