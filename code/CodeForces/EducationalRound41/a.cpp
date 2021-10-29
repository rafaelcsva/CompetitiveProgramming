#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
bool marked[N];
int cnt[N];

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    int cntmk = 0;
    int ans = 0;

    for(int i = 0 ; i < m ; i++){
        int ai;

        scanf("%d", &ai);

        cnt[ai]++;

        if(!marked[ai]){
            cntmk++;
            marked[ai] = true;
        }

        if(cntmk == n){
            cntmk = 0;
            for(int i = 1 ; i <= n ; i++){
                cnt[i]--;
                marked[i] = cnt[i] > 0;
                cntmk += marked[i];
            }

            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}